#include "includes/graph.h"

void init(vertice *v, int size, int *numbers, int arrsize){
  for (int i = 0; i < size; i++) {
    v[i].color = 'w';
    v[i].d = 999;
    v[i].f = 999;
    v[i].dad = -1;
    v[i].nadj = 0;
    updateAdj(v,i,numbers,arrsize,size);
  }
}

vertice search(vertice *v, int key, int size){
  for(int i = 0; i < size; i++){
    if(v[i].key == key){
      return v[i];
    }
  }
}

void updateAdj(vertice *v,int index, int *numbers, int size, int graphsize){
  int iterator=0;
  vertice *aux;
  vertice objective;
  for(int i=0; i < size; i += 2){
    if(numbers[i] == v[index].key){
      objective = search(v, numbers[i], graphsize);
      if(iterator==0){
        iterator++;
        aux = malloc(iterator*sizeof(vertice));
        aux[iterator-1] = objective;
        v[index].nadj++;
      } else {
        iterator++;
        aux = realloc(aux, iterator*sizeof(vertice));
        aux[iterator-1] = objective;
        v[index].nadj++;
      }
    }
  }
  v[index].adjs = aux;
}

int distinct(int *array, int size){
  int res = 0;
  for(int i=0; i<size; i++){
    int j = 0;
    for(j = 0; j < i; j++){
      if(array[i] == array[j])
        break;
    }
    if(i == j){
      res++;
    }
  }
  return res;
}

void newGraph(vertice *v, int *array, int size){
  int res = 0;
  for(int i=0; i<size; i++){
    int j = 0;
    for(j = 0; j<i; j++){
      if(array[i] == array[j])
        break;
    }
    if(i == j){
      v[res].key = array[i];
      res++;
    }
  }
}

void bfs(){

}

void dfs(vertice *v, int size){
  int time=0;
  for (int i = 0; i < size; i++) {
    if(v[i].color = 'w'){
      dfsVisit(v, &v[i], &time);
    }
  }
}

void dfsVisit(vertice *v, vertice *u, int *time){
  time += 1;
  u->d = time;
  u->color = 'g';
  for(int j = 0; j < u->nadj; j++){
    if(u->adjs[j].color == 'w'){
      u->adjs[j].dad = u->key;
      dfsVisit(v, &u->adjs[j], time);
    }
  }
  u->color = 'b';
  time += 1;
  u->f = time;
  printf("%d\n", time);
}

int main(int argc, char **argv){
  if(argc < 3){
    printf("## Inclua os arquivos de entrada e saida\n");
    exit(1);
  } else {
    FILE *arqin, *arqout;
    char pmodus, modus, *tok, content[200];
    vertice *vertices;
    int initialVertice, dsts;
    int iterator=0;
    int *numbers = malloc(sizeof(int));

    arqin = fopen(argv[1], "r");
    arqout = fopen(argv[2], "w");

    if(arqin == NULL || arqout == NULL){
      printf("## error opening files\n");
      exit(1);
    }

    fscanf(arqin, "%c\n", &pmodus); // read print modus
    fscanf(arqin, "%c\n", &modus); // read modus operandi
    fscanf(arqin, "%s[^\n]", content); // read content of x,y
    tok = strtok(content, " (),\n");
    while(tok != NULL){
      iterator++;
      numbers = (int *)realloc(numbers, iterator*sizeof(int));
      numbers[iterator-1] = atoi(tok);
      tok = strtok(NULL, " (),\n");
    }

    dsts =  distinct(numbers, iterator);
    vertices = malloc(dsts * sizeof(vertice));
    newGraph(vertices, numbers, iterator);
    init(vertices,dsts,numbers,iterator);

    dfs(vertices,dsts);

    if(modus == 'B' || modus == 'b'){
      fscanf(arqin, "%d", &initialVertice);
    }
  }

}


/*
criar um vetor alocado dinamicamente em cada um dos vertices de acordo com suas conexões???????
vetor de structs dos vertices

*/

#include "includes/graph.h"

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

int main(int argc, char **argv){
  if(argc < 3){
    printf("## Inclua os arquivos de entrada e saida\n");
    exit(1);
  } else {
    FILE *arqin, *arqout;
    char pmodus, modus, *tok, content[200];
    vertice *vertices;
    int init, iterator=0, dsts;
    int *numbers;

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
    vertices = malloc(dsts * sizeof(vertices));

    for(int i = 0; i < iterator; i++){
      // printf("%d\n", numbers[i]);
    }
    if(modus == 'B' || modus == 'b'){
      fscanf(arqin, "%d", &init);
    }
  }

}


/*
criar um vetor alocado dinamicamente em cada um dos vertices de acordo com suas conexões???????
vetor de structs dos vertices

*/

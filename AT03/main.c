#include "includes/remissive.h"

void initTree(PtrTree *tree){
  (*tree) = NULL;
}

void initList(List *node){
	node->first = NULL;
  node->last = NULL;
	node->size = 0;
}

bool insert(PtrTree *tree, char *word){
  // INSERE NOVO NÓ NA ARVORE
  if((*tree) == NULL){
    // printf("Vazio\n");
    (*tree) = malloc(sizeof(NodeTree));
    (*tree)->left = NULL;
    (*tree)->right = NULL;
    initList(&(*tree)->obj.list);

    strcpy(((*tree)->obj.word), word);
    return (true);
  }

  if(strcmp((*tree)->obj.word, word) == 0){
    return (false);
  }

  if(strcmp((*tree)->obj.word, word) > 0){
    return insert(&(*tree)->left, word);
  } else {
    return insert(&(*tree)->right, word);
  }
}

void nOcurrence(PtrTree *tree, int page){
  // NOVA OCORRENCIA ENCONTRADA DA PALAVRA
  // INSERE NÓ NÓ DE ARVORE -> OBJETO
  PtrNode new;
  new = (PtrNode)malloc(sizeof(PtrNode));
  new->element.key = page;
  new->next = NULL;

  if((*tree)->obj.list.size == 0 || (*tree)->obj.list.first == NULL){
    (*tree)->obj.list.first = new;
    (*tree)->obj.list.last = new;
    (*tree)->obj.list.size++;
  } else {
    if((*tree)->obj.list.last->element.key == page) return;
    (*tree)->obj.list.last->next = new;
    (*tree)->obj.list.last = new;
    (*tree)->obj.list.size++;
  }
}

bool search(PtrTree *tree, char *word, int page){
  if((*tree) == NULL){
    return (false);
  }

  if(strcmp((*tree)->obj.word, word) == 0){
    nOcurrence(&(*tree), page);
    return (true);
  }

  if(strcmp((*tree)->obj.word, word) > 0){
    search(&(*tree)->left, word, page);
  }

  if(strcmp((*tree)->obj.word, word) < 0){
    search(&(*tree)->right, word, page);
  }
}

void write(FILE *arqout, PtrTree *tree){
    if((*tree) == NULL) return;
    write(arqout, &(*tree)->left);
    PtrNode aux;
    aux = (*tree)->obj.list.first;
    fprintf(arqout, "%s: ", (*tree)->obj.word);
    while(aux != NULL){
      fprintf(arqout, "%i, ", aux->element.key);
      aux = aux->next;
    }
    fprintf(arqout, "\n");
    write(arqout, &(*tree)->right);
}

int main(int argc, char **argv){
  PtrTree tree;
  char txt[300];
  char *tok;
  PtrTree node;
  int page=0;
  if(argc < 3){
    printf("## Necessário inclusão dos arquivos de entrada\n");
  } else {
    initTree(&tree);
    FILE *arqin = NULL;
    FILE *arqout = NULL;

    arqin = fopen(argv[1], "r");
    arqout = fopen(argv[2], "w");

    if (arqin == NULL || arqout == NULL){
      printf("## Erro ao abrir os arquivos\n");
      exit(1);
    }

    fscanf(arqin, "%s[^\n]", &txt);
    tok = strtok(txt, " .()<:,>\n");
    if(strcmp(tok, "termos") == 0){
      tok = strtok(NULL, " .()<:,>\n");
      while(tok != NULL){
        insert(&tree, tok);
        tok = strtok(NULL, " .()<:,>\n");
      }
    }

    while(fgets(txt, 299, arqin) != NULL){
      tok = strtok(txt, " .()<:,>\n");
      while(tok != NULL){
        if(strcmp(tok, "page") == 0){
          page++;
        }
        search(&tree, tok, page);
        tok = strtok(NULL, " .()<:,>\n");
      }
    }
    write(arqout, &tree);
    printf("## File Write ##\n");

    fclose(arqin);
    fclose(arqout);
  }
  return 0;
}

#include "includes/AVL.h"

// queue implementations

void initQueue(queue *queue){
  queue->start = NULL;
  queue->end = NULL;
  queue->count = 0;
}

void enqueue(queue *queue) {
    PtrQueue aux;
    ObQueue x;

    aux = (PtrQueue) malloc(sizeof (nodeQueue));

    aux->obj = x;

    if (queue->count == 0) {
        queue->start = aux;
        queue->end = aux;
        aux->next = NULL;
    } else {
        aux->next = NULL;
        queue->end->next = aux;
        queue->end = queue->end->next;
    }
    queue->contador++;
}

Objeto dequeue(queue *queue) {
    if(queue->count == 0){
        printf("## Queue Empty\n");
    }else{

    ptrNoFila aux;

    aux = queue->start;
    queue->start = queue->start->next;

    Objeto ret = aux->obj;
    free(aux);

    queue->count--;

    return(ret);

    }
}

// AVL Implementations

void initTree(Pointer *node){
  (*node) = NULL;
}

void destroyTree(Pointer *node){
  // implementation  to destroy tree
}

bool insert(Pointer *node, Object ob){
  if((*node) == NULL){
    (*node) = malloc(sizeof(NodeAVL));
    (*node)->left = NULL;
    (*node)->right = NULL;
    (*node)->father = NULL;
    (*node)->element.key = ob.key;
    (*node)->bF = 0;
    printf("## Element Included, %d\n", (*node)->element.key);
    return (true);
  }
  if((*node)->element.key == ob.key){
    return (false);
  }

  bool ins;
  if(ob.key > (*node)->element.key){
    ins = insert(&(*node)->right, ob);
  } else {
    ins = insert(&(*node)->left, ob);
  }

  int rh = heightTree(&(*node)->right);
  // printf("Altura Dir. %d\n", rh);
  int lh = heightTree(&(*node)->left);
  // printf("Altura Esq. %d\n", lh);
  int bf = rh-lh;
  if(bf >= 2 || bf <= -2){
    printf("Unbalanced..\n");
    makeRotations(&(*node), bf);
  }
}

void makeRotations(Pointer *node, int bf){
  Pointer aux;
  if(bf == 2){
    aux = ((*node)->right);
    // Right Rotations
    if(heightTree(&(aux)->right) > heightTree(&(aux)->left)){
      // RSD
      printf("RSD\n");
      singleLeftRotation(&(*node));
    } else {
      // RDD
      printf("RDD\n");
      doubleLeftRotation(&(*node));
    }
  } else if(bf == -2){
    aux = (*node)->left;
    // left rotations
    if(heightTree(&aux->left) >= heightTree(&aux->right)){
      printf("RSE\n");
      singleRightRotation(&(*node));
    } else {
      printf("RDE\n");
      doubleRightRotation(&(*node));
    }
  }
}

int heightTree(Pointer *node){
  int lh, rh;
  if((*node)==NULL) return 0;

  else {
    lh = heightTree(&(*node)->left);
    rh = heightTree(&(*node)->right);
  }

  if(lh > rh)
    return (lh+1);
  else
    return (rh+1);
}

void singleLeftRotation(Pointer *node){
  Pointer u = (*node)->right;
  (*node)->right = u->left;
  u->left = (*node);
  (*node)->bF = 0;
  (*node) = u;
}

void singleRightRotation(Pointer *node){
  Pointer u = (*node)->left;
  (*node)->left = u->right;
  u->right = (*node);
  (*node)->bF = 0;
  (*node) = u;
}

void doubleLeftRotation(Pointer *node){
  Pointer u,v;
  u = (*node)->right;
  v = u->left;
  (*node)->right = v->left;
  u->left = v->right;
  v->right = u;
  v->left = (*node);
  (*node) = v;
}

void doubleRightRotation(Pointer *node){
  Pointer u,v;
  u = (*node)->left;
  v = u->right;
  (*node)->left = v->right;
  u->right = v->left;
  v->right = (*node);
  v->left = u;
  (*node) = v;
}

bool removeItem(Pointer *node, int key){
  if((*node) == NULL) {
    printf("## Element not found\n");
    return (false);
  }

  if((*node)->element.key == key){
    // if((*node)->left == NULL && (*node)->right == NULL){
    //   printf("Esq e Dir vazia\nelemento: %d\n", (*node)->element.key);
    //   // (*node) = NULL;
    // }

    if((*node)->left == NULL){
      printf("Esq vazia\n");
      (*node) = (*node)->right;
      return (true);
    }

    if((*node)->right == NULL){
      printf("Dir vazia\n");
      (*node) = (*node)->left;
      return (true);
    }

    if((*node)->left != NULL && (*node)->right != NULL){
      printf("nenhum vazio\n");
      (*node) = getMaxAux(&(*node)->left);
      return (true);
    }
  }

  if(key < (*node)->element.key){
    removeItem(&(*node)->left, key);
  } else {
    removeItem(&(*node)->right, key);
  }

  int rh = heightTree(&(*node)->right);
  // printf("Altura Dir. %d\n", rh);
  int lh = heightTree(&(*node)->left);
  // printf("Altura Esq. %d\n", lh);
  int bf = rh-lh;
  if(bf >= 2 || bf <= -2){
    printf("Unbalanced..\n");
    makeRotations(&(*node), bf);
  }
}

Pointer getMaxAux(Pointer *node){
  Pointer aux;
  for(aux = (*node); aux->right != NULL; aux = aux->right);
  return aux;
}

Pointer getMinAux(Pointer *node){
  Pointer aux;
  for(aux = (*node); aux->left != NULL; aux = aux->left);
  return aux;
}

void write(FILE *arq, Pointer *tree){
  // implementation to write in file
}

void preOrder(Pointer *node){
  if((*node)== NULL) return;
  printf("%d ", (*node)->element.key);
  preOrder(&(*node)->left);
  preOrder(&(*node)->right);
}

void inOrder(Pointer *node){
  if(*node == NULL) return;
  inOrder(&(*node)->left);
  printf("%d ", (*node)->element.key);
  inOrder(&(*node)->right);
}

int main(int argc, char **argv){

  if(argc < 3){
    printf("## Necessário Inclusão dos arquivos de entrada \n");
  } else {
    Pointer tree;
    initTree(&tree);
    Object ob;
    char lixo;
    int num;

    FILE *arqin = NULL;
    FILE *arqout = NULL;

    arqin = fopen(argv[1], "r");
    arqout = fopen(argv[2], "w");

    if(arqin == NULL || arqout == NULL){
      printf("## Erro ao abrir os arquivos\n");
      exit(1);
    }

    // read insertion numbers
    while(fscanf(arqin, "%d%c", &num, &lixo) == 2 && lixo != '\n'){
      ob.key = num;
      insert(&tree, ob);
    }
    ob.key = num;
    insert(&tree, ob);
    // end of tree insertion


    // read remove numbers
      while(fscanf(arqin, "%d%c", &num, &lixo) != EOF){
        removeItem(&tree, num);
      }

    // end of tree removal

    // BEF REMOVE
    fprintf(arqout, "[*]antes\n");
    // write(arqout, &tree);
    printf("## 50%% of File Write ##\n");

    // AFTER REMOVE
    fprintf(arqout, "\n\n[*]depois\n");
    // write(arqout, &tree);
    printf("## File Write ## \n");

    printf("\n\n\n");
    preOrder(&tree);



    fclose(arqin);
    fclose(arqout);
  }
}

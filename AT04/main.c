#include "includes/AVL.h"

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
  rh = heightTree(&(*node)->right);
  lh = heightTree(&(*node)->left);
  bf = rh-lh;
  (*node)->bF = bf;
}

void makeRotations(Pointer *node, int bf){
  Pointer aux;
  if(bf == 2){
    aux = ((*node)->right);
    // Right Rotations
    if(heightTree(&(aux)->right) > heightTree(&(aux)->left)){
      // RSD
      // printf("RSD\n");
      singleLeftRotation(&(*node));
    } else {
      // RDD
      // printf("RDD\n");
      doubleLeftRotation(&(*node));
    }
  } else if(bf == -2){
    aux = (*node)->left;
    // left rotations
    if(heightTree(&aux->left) >= heightTree(&aux->right)){
      // printf("RSE\n");
      singleRightRotation(&(*node));
    } else {
      // printf("RDE\n");
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
  int lh1 = heightTree(&(*node)->left->left);
  int rh1 = heightTree(&(*node)->left->right);
  int lh2 = heightTree(&(*node)->right->left);
  int rh2 = heightTree(&(*node)->right->right);
  (*node)->left->bF = lh1-rh1;
  (*node)->right->bF = lh2-rh2;
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
  int lh1 = heightTree(&(*node)->left->left);
  int rh1 = heightTree(&(*node)->left->right);
  int lh2 = heightTree(&(*node)->right->left);
  int rh2 = heightTree(&(*node)->right->right);
  (*node)->left->bF = lh1-rh1;
  (*node)->right->bF = lh2-rh2;
}

bool removeItem(Pointer *node, int key){
  if((*node) == NULL) {
    printf("## Element not found\n");
    return (false);
  }

  if((*node)->element.key == key){
    if((*node)->left == NULL){
      // printf("Esq vazia\n");
      (*node) = (*node)->right;
      return (true);
    }

    if((*node)->right == NULL){
      // printf("Dir vazia\n");
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
    makeRotations(&(*node), bf);
  }
}

Pointer getMaxAux(Pointer *node){
  Pointer aux;
  for(aux = (*node); aux->right != NULL; aux = aux->right);
  return aux;
}

void printAux(FILE *arq, Pointer *node, int level){
  if ((*node) == NULL) return;
  if(level == 1){
    fprintf(arq, "%d[%d], ", (*node)->element.key, (*node)->bF);
  } else if(level > 1){
    printAux(arq, &(*node)->left, level-1);
    printAux(arq, &(*node)->right, level-1);
  }
}

void print(FILE *arq, Pointer *node){
  int h = heightTree(&(*node));
  for (int i=0; i <= h; i++) {
    printAux(arq, &(*node),i);
    fprintf(arq, "\n");
  }
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

    // BEF REMOVE
    fprintf(arqout, "[*]antes\n");
    print(arqout,&tree);

    // read remove numbers
      while(fscanf(arqin, "%d%c", &num, &lixo) != EOF){
        removeItem(&tree, num);
      }

    // end of tree removal

    // AFTER REMOVE
    fprintf(arqout, "\n\n[*]depois\n");
    print(arqout,&tree);
    printf("######################################################\n");
    printf("## File Write ## \n");
    printf("######################################################\n");



    fclose(arqin);
    fclose(arqout);
  }
}

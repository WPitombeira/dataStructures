#include "includes/binaryTree.h"
#include <time.h>

void initTree(PtrTree *node){
  (*node) = NULL;
}

void destroyTree(PtrTree *node){
  // implementation to destroy tree
}

bool insertItem(PtrTree *node, Object ob){
  if((*node) == NULL){
    (*node) = malloc(sizeof(PtrTree));
    (*node)->element = ob;
    (*node)->left = NULL;
    (*node)->right = NULL;
    printf("## Inserted element with value {%d}\n", (*node)->element.key);
    return (true);
  }
  if((*node)->element.key == ob.key){
    return (false);
  }
  if((*node)->element.key > ob.key) {
    return insertItem(&(*node)->left, ob);
  } else {
    return insertItem(&(*node)->right, ob);
  }
}

bool removeItem(PtrTree *node, int key){

}

bool findItem(PtrTree *node, int key, Object *ret){
  if(*node == NULL) return (false);

  if((*node)->element.key == key){
    *ret = (*node)->element;
    return (true);
  }

  if(key < (*node)->element.key){
    findItem(&(*node)->left, key, ret);
  } else {
    findItem(&(*node)->right, key, ret);
  }
}

bool isEmpty(PtrTree *node){
  return (*node = NULL) ? true : false;
}

int sizeTree(PtrTree *node){
  // retorna o tamanho da arvore, cada nó = 1 tamanho
}

int maxDepth(PtrTree *node){
  // retorna o máximo elemento?
}

void preOrder(PtrTree *node){
  if(*node == NULL) return;
  printf("%d ", (*node)->element.key);
  preOrder(&(*node)->left);
  preOrder(&(*node)->right);
}

void posOrder(PtrTree *node){
  if(*node == NULL) return;
  posOrder(&(*node)->left);
  posOrder(&(*node)->right);
  printf("%d ", (*node)->element.key);
}

void inOrder(PtrTree *node){
  if(*node == NULL) return;
  inOrder(&(*node)->left);
  printf("%d ", (*node)->element.key);
  inOrder(&(*node)->right);
}

PtrTree maximum(PtrTree *node){
  if((*node)->right == NULL) return (*node);
  return maximum(&(*node)->right);
}

PtrTree minimum(PtrTree *node){
  if((*node)->left == NULL) return (*node);
  return minimum(&(*node)->left);
}

PtrTree minimumIterative(PtrTree *node){
  PtrTree aux;
  for(aux = (*node); aux->left != NULL; aux = aux->left);
  return aux;
}

PtrTree maximumIterative(PtrTree *node){
  PtrTree aux;
  for(aux = (*node); aux->right != NULL; aux = aux->right);
  return aux;
}

int main(){

  NodeTree *tree;
  initTree(&tree);
  Object ob;
  for (int i = 0; i < 10; i++) {
    ob.key = rand()%100;
    insertItem(&tree, ob);
  }
  printf("Elementos na Arvore: { ");
  inOrder(&tree);
  printf("}\n");
  if(findItem(&tree, 86, &ob)){
    printf("Objeto -> %d\n", ob.key);
  }
  PtrTree max;
  max = maximum(&tree);
  printf("Maximo -> %d", max->element.key);
}

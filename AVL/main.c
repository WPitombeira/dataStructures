#include "includes/AVL.h"

bool insert(Pointer node, Object ob){
  if((*node) == NULL){
    (*node)->element = ob;
    (*node)->bF = 0;
    return (true);
  } else if((*node)->element == ob){
    return (false);
  }

  bool ins;
  if(ob.key > (*node)->element.key){
    ins = insert((*node)->right);
  } else {
    ins = insert((*node)->left);
  }

  if(ins = FALSE) return (false);

  int rh = heightTree((*node)->right);
  int lh = heightTree((*node)->left);
  int bf = rh-lh;
  if(bf == -2 || bf == 2){
    printf("Unbalanced..");
    makeRotations(node, bf);
  }
}

void makeRotations(Pointer node, int bf){
  Pointer aux;
  if(bf == 2){
    aux = (*node)->right);
    // Right Rotations
    if(heightTree(aux->right) > heightTree(aux->left)){
      // RSD
      singleLeftRotation(&(*node));
    } else {
      // RDD
      doubleLeftRotation(&(*node));
    }
  } else if(bf == -2){
    aux = (*node)->left;
    // left rotations
    if(heightTree(aux->left) >= heightTree(aux->right){
      singleRightRotation(&(*node));
    } else {
      doubleRightRotation(&(*node));
    }
  }
}

int heightTree(Pointer node){
  if(node == NULL){
    return 0;
  } else {
    return (node->height);
  }
}

int updateHeight(Pointer leftNode, Pointer rightNode){
  int lh, rh;

  lh = heightTree(leftNode);
  rh = heightTree(rightNode);
  return (lh>rh) ? (lh+1) : (rh+1);
}


void singleLeftRotation(Pointer *node){
  Pointer u = (*node)->right;
  Pointer p = (*node);
  p->right = u->left;
  u->left = p;
  p->bF = 0;
  p = u;
}

void singleRightRotation(Pointer *node){
  Pointer u = (*node)->left;
  Pointer p = (*node);
  p->left = u->right;
  u->right = p;
  p->bF = 0;
  p = u;
}

void doubleLeftRotation(Pointer *node){
  Pointer p = (*node);
  Pointer u = (*node)->right;
  Pointer v = u->left;
  p->right = v->left;
  u->left = v->right;
  v->right = u;
  v->left = p;
  p = v;
}

void doubleRightRotation(Pointer *node){
  Pointer p = (*node);
  Pointer u = (*node)->left;
  Pointer v = u->right;
  p->left = v->right;
  u->right = v->left;
  v->right = p;
  v->left = u;
  p = v;
}


int main(){
  Pointer tree;
  initTree(&(*tree));
}

#ifndef AVL_h
#define AVL_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  char key;
} Object;

typedef struct NodeAVL *Pointer;

typedef struct NodeAVL {
  Pointer left;
  Pointer right;
  Pointer father;
  Object element;
  int bF;
}

void initAVL(Pointer *node);
bool insert(Pointer *node, Object ob);
void makeRotations(Pointer node, int bf);
int heightTree(Pointer node);
int updateHeight(Pointer leftNode, Pointer rightNode);
void singleLeftRotation(Pointer *node);
void singleRightRotation(Pointer *node);
void singleRightRotation(Pointer *node);
void doubleLeftRotation(Pointer *node);
void doubleRightRotation(Pointer *node);

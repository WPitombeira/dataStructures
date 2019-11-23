#ifndef AVL_h
#define AVL_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  int key;
} Object;

typedef struct NodeAVL *Pointer;

typedef struct NodeAVL {
  Pointer left;
  Pointer right;
  Pointer father;
  Object element;
  int bF;
} NodeAVL;

void initAVL(Pointer *node);
bool insert(Pointer *node, Object ob);
void makeRotations(Pointer *node, int bf);
int heightTree(Pointer *node);
int updateHeight(Pointer *leftNode, Pointer *rightNode);
void singleLeftRotation(Pointer *node);
void singleRightRotation(Pointer *node);
void singleRightRotation(Pointer *node);
void doubleLeftRotation(Pointer *node);
void doubleRightRotation(Pointer *node);
void print(Pointer *node);
int maxDepth(Pointer *node);
int height(Pointer *node);
Pointer getMaxAux(Pointer *node);
Pointer getMinAux(Pointer *node);


// queue headers

typedef struct {
    int key;
} ObQueue;

typedef struct nodeQueue *PtrQueue;

typedef struct nodeQueue {
    PtrQueue next;
    ObQueue obj;
} nodeQueue;

typedef struct {
    PtrQueue start;
    PtrQueue end;
    int count;
} queue;

void initQueue(queue *queue);
void enqueue(queue *queue);



#endif

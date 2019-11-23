
#ifndef remissive_h
#define remissive_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct  {
    int key;
} Object;

typedef struct NodeList *PtrNode;

typedef struct NodeList {
    Object element;
    PtrNode next;
    PtrNode prev;
} NodeList;

typedef struct {
    PtrNode first;
    PtrNode last;
    int size;
} List;

typedef struct {
  List list;
  char word[60];
} ObjTree;

typedef struct NodeTree *PtrTree;

typedef struct NodeTree {
  PtrTree left;
  PtrTree right;
  ObjTree obj;
} NodeTree;

bool insert(PtrTree *tree, char *word);
void nOcurrence(PtrTree *tree, int page);
bool search(PtrTree *tree, char *word, int page);
void initList(List *node);
void write(FILE *arqout, PtrTree *tree);


#endif

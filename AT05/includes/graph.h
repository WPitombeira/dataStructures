#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct vertice *vPointer;

typedef struct vertice {
  int key;
  char color;
  int d;
  int f;
  int dad;
  vPointer adjs;
  int nadj;
} vertice;

void init(vertice*, int, int*, int);
int distinct(int *array, int size);
void updateAdj(vertice*, int, int*, int, int);
void newGraph(vertice*, int*, int);

void bfs();
void dfs(vertice*, int);
void dfsVisit(vertice*, vertice*, int*);


#endif

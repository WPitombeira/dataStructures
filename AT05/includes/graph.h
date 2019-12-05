#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  int key;
  char color;
  int d;
  int f;
  int dad;
  int *adjs;
} vertice;

void init(vertice*);

#endif

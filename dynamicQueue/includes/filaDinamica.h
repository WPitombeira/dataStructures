//
// Created by root on 10/09/2019.
//

#ifndef FILADINAMICA_FILADINAMICA_H
#define FILADINAMICA_FILADINAMICA_H

typedef struct {
   int key;
} Object;

typedef struct NoFila *ptrNoFila;

typedef struct {
    Object obj;
    ptrNoFila next;
} NoFila;

typedef struct {
    ptrNoFila start;
    ptrNoFila end;
    int size;
} DynamicQueue;

#endif //FILADINAMICA_FILADINAMICA_H

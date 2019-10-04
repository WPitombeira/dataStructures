//
//  staticStack.h
//  Stacks
//
//  Created by Rafael Gomes Mantovani on 22/03/19.
//  Copyright © 2019 Rafael Gomes Mantovani. All rights reserved.
//

#ifndef staticStack_h
#define staticStack_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXTAM 5

typedef struct {
    int key;
} Object;

typedef struct {
    Object array[MAXTAM];
    int top;
} StaticStack;


/* funções de manipulação */
void init(StaticStack *stack);
bool isEmpty(StaticStack *stack);
bool isFull(StaticStack *stack) ;
void push(Object obj, StaticStack *stack);
Object pop(StaticStack *stack);
int size(StaticStack *stack);
Object top(StaticStack *stack);
void print(StaticStack *stack);

#endif /* staticStack_h */
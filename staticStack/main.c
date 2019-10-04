#include "statickStack.h"

void init(StaticStack *stack) {
    for (int i = 0; i < MAXTAM; i++) {
        Object x;
        x.key = 0;
        stack->array[i] = x;
    }
    stack->top = 0;
}

bool isEmpty(StaticStack *stack) {
    return (stack->top == 0) ? true : false;
}

bool isFull(StaticStack *stack) {
    return (stack->top == MAXTAM) ? true : false;
}

void push(Object obj, StaticStack *stack) {
    if(isFull(stack)){
        printf("Pilha Cheia\n");
    } else {
        int top = stack->top;
        stack->array[top].key = obj.key;
        stack->top = stack->top + 1;
        printf("Pushed '%i'\n", obj.key);
    }
}

Object pop(StaticStack *stack) {
    if(isEmpty(stack)){
        printf("Pilha Vazia\n");
    } else {
        Object x;
        Object nTop;
        nTop.key = 0;

        stack->top = stack->top - 1;
        int top = stack->top;
        x = stack->array[top];

        stack->array[top] = nTop;
        return x;
    }
}

int size(StaticStack *stack) {
    return stack->top;
}

Object top(StaticStack *stack) {
    int top = stack->top;
    Object x;
    x.key = stack->array[top].key;

    return x;
}

void print(StaticStack *stack) {
    printf("{ ");
    for (int i = 0; i < MAXTAM; i++) {
        printf("%i ", stack->array[i].key);
    }
    printf("}");
}

int main(){
    StaticStack stack;
    init(&stack);
    Object obj;
    obj.key = 8;
    push(obj, &stack);
    obj.key = 32;
    push(obj, &stack);
    obj.key = 34;
    push(obj, &stack);
    obj.key = 77;
    push(obj, &stack);
    obj.key = 55;
    push(obj, &stack);
    print(&stack);
}
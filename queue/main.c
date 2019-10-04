#include "queue.h"

void initQueue(StaticQueue *queue){
    queue->size=0;
    queue->start=0;
    queue->end=-1;
}

void enqueue(Object x, StaticQueue *queue){
    if(!isFull(queue)){
        queue->end = increaseIndex(queue->end);
        queue->array[queue->end] = x;
        queue->size++;
    } else {
        printf("Queue is Full!\n");
    }
}

void printQueue(StaticQueue *queue){
    int iterator = queue->start;

    if(queue->size == 0){
        printf("Queue = {} \n");
    } else {
        printf("Queue = { ");
        while(iterator != queue->end){
            printf("%d ", queue->array[iterator].key);
            if(iterator == (MAXTAM-1)){
                iterator==0;
            } else {
                iterator++;
            }
        }
        printf("%d }\n", queue->array[queue->end].key);
    }
}

bool isEmpty(StaticQueue *queue){
    return (queue->size==0) ? true : false;
}

bool isFull(StaticQueue *queue){
    return (queue->size==MAXTAM) ? true : false;

}

int sizeQueue(StaticQueue *queue){
    return queue->size;
}

int increaseIndex(int i){
    i++;
    if(i == MAXTAM){
        i=0;
    }
    return i;
}

Object dequeue(StaticQueue *queue){

}

Object first(StaticQueue *queue){
    return queue->array[queue->start];
}

Object last(StaticQueue *queue){
    return queue->array[queue->end];
}

int main() {
    StaticQueue queue;
    initQueue(&queue);
    printf("%d", increaseIndex(5));
    return 0;
}
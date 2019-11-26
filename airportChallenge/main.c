#include "includes/airport.h"

void initQueue(queue *q){
  q->count = 0;
  q->start = 0;
  q->end = -1;
}

bool enqueue(queue *q, plane p){
  if(!isFull(q)){
    q->end = increaseIndex(q->end);
    q->planes[q->end] = p;
    q->count++;
    return(true);
  } else {
    printf("## This Queue is Full ##\n");
    return(false);
  }
}


int main(int argc, char **argv){



  return 0;
}

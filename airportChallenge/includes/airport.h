#ifndef AIRPORT_H
#define AIRPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAXTAM 20

typedef struct {
  int id; // identification of the plane
  int fuel; // random percentage of fuel (0-100) in units of time
} plane;

typedef struct {
  int count; // quantity of planes in the queue
  int start; // start of the queue
  int end; // end of the queue
  plane planes[MAXTAM]; // array of planes
} queue;

typedef struct {
  queue p1l1; // pit 1 landing 1
  queue p1l2; // pit 1 landing 2
  queue p2l1; // pit 2 landing 1
  queue p2l2; // pit 2 landing 2
  queue p1toq; // pit 1 take off
  queue p2toq; // pit 2 take off
  queue p3toq; // pit 3 take off
  int landingWait, takeOffWait, outFuel;
  int nLands, nTakeOffs, nPlanes;
} airport;


// queue manipulation functions

void initQueue(queue*);
bool enqueue(queue*,plane);
plane dequeue(queue*);
int size(queue*);
bool isEmpty(queue*);
bool isFull(queue*);
int increaseIndex(int); // function to calculate the index of the queue

// airport manipulation funciotns
void initAirport (airport*);
void land(airport*,plane*,int);
void takeOff(airport*, plane*,int);
void printResults(airport*);
void updateFuel(airport*);

#endif

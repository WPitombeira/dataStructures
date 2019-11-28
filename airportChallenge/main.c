#include "includes/airport.h"

void initQueue(queue *q){
  q->count = 0;
  q->start = 0;
  q->end = -1;
}

bool enqueue(queue *q, plane p){
  if(isFull(q)){
    printf("## This Queue is Full ##\n");
    return(false);
  } else {
    q->end = increaseIndex(q->end);
    q->planes[q->end] = p;
    q->count++;
    return(true);
  }
}

int increaseIndex(int n){
  n++;
  if(n == MAXTAM) n=0;

  return n;
}

int size(queue *q){
  return q->count;
}

bool isFull(queue *q){
  return (q->count==MAXTAM) ? (true) : (false);
}

bool isEmpty(queue *q){
  return (q->count==0) ? (true) : (false);
}

void initAirport(airport *ap){
  initQueue(&ap->p1l1); // initialize queue of pit 1 landing 1
  initQueue(&ap->p1l2); // initialize queue of pit 1 landing 2
  initQueue(&ap->p2l1); // initialize queue of pit 2 landing 1
  initQueue(&ap->p2l2); // initialize queue of pit 2 landing 2
  initQueue(&ap->p1toq); //initialize queue of pit 1 take off
  initQueue(&ap->p2toq); //initialize queue of pit 2 take off
  initQueue(&ap->p3toq); //initialize queue of pit 3 take off
  ap->landingWait=0;
  ap->takeOffWait=0;
  ap->outFuel=0;
  ap->nLands=0;
  ap->nTakeOffs=0;
  ap->nPlanes=0;
}

int main(int argc, char **argv){
  airport ap;
  int runningTime, fun;
  plane p;

  srand(time(NULL));

  printf("Escolha uma unidade de tempo para funcionamento do Simulador (1-?): ");
  scanf("%d", &runningTime);

  initAirport(&ap);

  for(int run=1; run <= runningTime; run++){
    // quando inicia unidade de tempo
      // REMOVE 1 AVIÃO DAS FILAS DE TAKEOFF E JOGA FORA
      // REMOVE 1 AVIÃO DAS FILAS DE POUSO E JOGA ELES PRA FILA DE TAKEOFF (pistas 1, 2 ou 3)

    printf("Tempo %d\n", run);

    fun = rand()%3;
    printf("Aviões Pousando: %d\n", fun);
    for(int i=0; i <= fun; i++){
      if(fun > 0 && i>0){
        // entrada de avião
        p.fuel = rand()%100;
        p.id = ap.nPlanes+1;
        ap.nPlanes++;
        land(&ap, &p, run);
      }
    }

    fun = rand()%3;
    printf("Aviões Saindo: %d\n", fun);
    for(int i=0; i <= fun; i++){
      if(fun > 0 && i>0){
        // entrada de avião
        land(&ap, &p, run);
      }
    }

    // validações

      // SE Pista 1 entrada == vazio
        // verifica se existem aviões para sair
          // caso sim, lança avião (de 0 a 3)
        // se não
          // termina unidade de Tempo
      // se não
        // verifica se pista 2 entrada == vazio
          // se sim, lança avião (de 0 a 3)
        // se não
          // termina unidade de tempo
      // se não
        // lança avião usando pista 3

  }

  // printResults(&ap);


  return 0;
}

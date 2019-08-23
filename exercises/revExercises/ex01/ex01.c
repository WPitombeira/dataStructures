#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *totalMinutos, *horas=0, *minutos=0;

void calcTime(int * totalMin, int * h, int * min){
    *h = floor(*totalMin/60);
    *min = (*totalMin-(*h*60));
}

int main()
{
    printf("Exercicio 1 <-> Lista de Revisao\n\n");

    printf("Digite o total de minutos: ");
    scanf("%d", &totalMinutos);

    calcTime(&totalMinutos, &horas, &minutos);

    printf("\n\nHoras %d, Minutos %i", horas, minutos);

    return 0;
}

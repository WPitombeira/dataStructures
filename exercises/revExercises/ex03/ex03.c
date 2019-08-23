#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, pot, res;

int squareByY(int x, int y){
    if(y==1){
        return x;
    } else {
        return x * squareByY(x, y-1);
    }
}

int main()
{
    printf("Exercicio 3 <-> Lista de Revisao\n\n");

    printf("Digite o numero a ser elevado ");
    scanf("%i", &n);

    printf("Digite a potencia que o numero sera elevado ");
    scanf("%i", &pot);

    res = squareByY(n, pot);

    printf("O Numero %i elevado a potencia %i resulta em %i", n, pot, res);

    return 0;
}

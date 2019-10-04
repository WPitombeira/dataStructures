#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c, baskara, x1, x2;

    printf("Digite o valor de A \n");
    scanf("%f",&a);

    printf("Digite o valor de B \n");
    scanf("%f",&b);

    printf("Digite o valor de C \n");
    scanf("%f",&c);

    baskara= pow(b,2) - 4 * a * c;

    //comparação
    if(baskara >= 0 ){

        x1= (-b + sqrt(baskara)) / (2*a);
        x2= (-b - sqrt(baskara)) / (2*a);

        printf("As raízes da equação são: x1 = %.2lf e x2 = %.2lf \n", x1,x2);

    }else {
        printf("Não existe a raiz no conjunto dos reais\n");
    } //fim da comparação

    return 0;
}
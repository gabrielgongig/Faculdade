#include <stdio.h>
#include <math.h>
int main()
{
    int cod, qtd;
    float valor;
    scanf("%d%d", &cod, &qtd);

    switch (cod)
    {
    case 1:
        valor = qtd * 4;
        break;

    case 2:
        valor = qtd * 4.5;
        break;

    case 3:
        valor = qtd * 5;
        break;

    case 4:
        valor = qtd * 2;
        break;

    case 5:
        valor = qtd * 1.5;
        break;
    }
    printf("Total: R$ %.2f\n", valor);
    return 0;
}
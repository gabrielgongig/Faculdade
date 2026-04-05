#include <stdio.h>

int main()
{

    int a;
    int b;
    int c;
    int d;
    int resultado;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    resultado = (a * b - c * d);
    printf("DIFERENCA = %d\n", resultado);
}
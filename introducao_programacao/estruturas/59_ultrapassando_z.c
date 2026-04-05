#include <stdio.h>

int main()
{
    int x = 1, z = 1, soma = 0, cont = 0;

    scanf("%d", &x);
    while (x >= z)
    {
        scanf("%d", &z);
    }
    while (soma <= z)
    {
        soma += x;
        x += 1;
        cont += 1;
    }
    printf("%d\n", cont);
}
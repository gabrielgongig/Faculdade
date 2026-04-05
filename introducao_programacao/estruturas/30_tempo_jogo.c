#include <stdio.h>
#include <math.h>
int main()
{
    int inicio, fim, tempo;
    scanf("%d%d", &inicio, &fim);

    if (fim > inicio)
    {
        tempo = fim - inicio;
        printf("O JOGO DUROU %d HORA(S)\n", tempo);
    }
    else if (fim == inicio)
    {
        printf("O JOGO DUROU 24 HORA(S)\n");
    }
    else if (inicio > fim)
    {
        tempo = (24 - inicio) + fim;
        printf("O JOGO DUROU %d HORA(S)\n", tempo);
    }
}
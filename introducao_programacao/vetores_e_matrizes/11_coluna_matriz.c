#include <stdio.h>

int main()
{
    float M[12][12], soma = 0;
    int coluna;
    char operacao;
    scanf("%d\n%c\n", &coluna, &operacao);

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%f", &M[i][j]);
        }
    }
    for (int i = 0; i < 12; i++)
    {
        soma += M[i][coluna];
    }
    if (operacao == 'S')
    {
        printf("%.1f\n", soma);
    }
    if (operacao == 'M')
    {
        printf("%.1f\n", soma / 12);
    }
}
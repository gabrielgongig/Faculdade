#include <stdio.h>

int main()
{
    float M[12][12];
    long double soma = 0;
    int ct = 0;
    char operacao;
    scanf("%c\n", &operacao);
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%f", &M[i][j]);
        }
    }
    for (int i = 1; i < 12; i++)
    {
        for (int j = 0; j <= (i - 1); j++)
        {
            soma += M[i][j];
            ct++;
        }
    }
    if (operacao == 'S')
    {
        printf("%.1Lf\n", soma);
    }
    if (operacao == 'M')
    {
        printf("%.1Lf\n", soma / ct);
    }
}

#include <stdio.h>

int main()
{
    double M[12][12];
    long double soma = 0;
    int sup, sup2, ct = 0, ct2 = 1;
    char operacao;
    scanf("%c\n", &operacao);
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%lf", &M[i][j]);
        }
    }
    for (int i = 7; i < 12; i++)
    {
        sup = i - (2 * ct2);
        sup2 = i - 1;
        ct2++;
        for (int j = sup; j <= sup2; j++)
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
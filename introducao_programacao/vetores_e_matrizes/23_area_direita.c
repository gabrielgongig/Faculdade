#include <stdio.h>

int main()
{
    double M[12][12];
    long double soma = 0;
    int sup, sup2, ct = 0;
    char operacao;
    scanf("%c\n", &operacao);
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%lf", &M[i][j]);
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        sup = 11;
        if (i <= 5)
        {
            sup2 = 12 - i;
        }
        if (i > 5)
        {
            sup2 = i + 1;
        }
        for (int j = sup; j >= sup2; j--)
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
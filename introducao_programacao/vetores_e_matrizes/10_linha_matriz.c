#include <stdio.h>
int main()
{
    float M[12][12], soma = 0;
    int linha;
    char operacao;
    scanf("%d\n%c\n", &linha, &operacao);
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%f", &M[i][j]);
        }
    }
    for (int i = 0; i < 12; i++)
    {
        soma += M[linha][i];
    }
    if (operacao == 'S')
    {
        printf("%.1f\n", soma);
    }
    else if (operacao == 'M')
    {
        printf("%.1f\n", soma / 12);
    }
}
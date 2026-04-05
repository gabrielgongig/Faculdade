#include <stdio.h>

#define L 12
#define C 10

int soma(int l, int c, int t[l][c]);
void ler(int l, int c, int t[l][c]);
void somames(int l, int c, int t[l][c]);
void somaprod(int l, int c, int t[l][c]);
void pvmes(int l, int c, int t[l][c]);
void mmvenda(int l, int c, int t[l][c]);

int main()
{
    int tab[L][C];

    ler(L, C, tab);
    int stotal = soma(L, C, tab);

    somames(L, C, tab);
    somaprod(L, C, tab);

    pvmes(L, C, tab);
    mmvenda(L, C, tab);

    printf("Vendas totais: %d\n", stotal);
    return 0;
}

void ler(int l, int c, int t[l][c])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &t[i][j]);
        }
    }
}

int soma(int l, int c, int t[l][c])
{
    int s = 0;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            s += t[i][j];
        }
    }
    return s;
}

void somames(int l, int c, int t[l][c])
{
    int s = 0;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            s += t[i][j];
        }
        printf("Mes: %d | Qtd: %d\n", i + 1, s);
        s = 0;
    }
}

void somaprod(int l, int c, int t[l][c])
{
    int s = 0;

    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < l; i++)
        {
            s += t[i][j];
        }
        printf("Produto: %d | Qtd: %d\n", j + 1, s);
        s = 0;
    }
}

void pvmes(int l, int c, int t[l][c])
{
    int maior, maiorc;

    for (int i = 0; i < l; i++)
    {
        maior = 0;
        maiorc = 0;

        for (int j = 0; j < c; j++)
        {
            if (t[i][j] > maior)
            {
                maior = t[i][j];
                maiorc = j;
            }
        }
        printf("Mes: %d | Produto mais vendido: %d\n", i + 1, maiorc + 1);
    }
}

void mmvenda(int l, int c, int t[l][c])
{
    int maior, maiorl;

    for (int j = 0; j < c; j++)
    {
        maior = 0;
        maiorl = 0;

        for (int i = 0; i < l; i++)
        {
            if (t[i][j] > maior)
            {
                maior = t[i][j];
                maiorl = i;
            }
        }
        printf("Produto: %d | Mes em que foi mais vendido: %d\n", j + 1, maiorl + 1);
    }
}
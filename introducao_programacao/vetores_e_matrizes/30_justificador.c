#include <stdio.h>
#include <string.h>
int ContDigito(int l, int c, char S[l][c]);
int main()
{
    int n = 1, maior, d;
    char S[51][51];

    while (n != 0)
    {
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++)
        {
            fgets(S[i], 50, stdin);
        }
        printf("\n");
        maior = ContDigito(n, 51, S);
        for (int i = 0; i < n; i++)
        {
            d = maior - (strlen(S[i]) - 1);
            for (int j = 0; j < d; j++)
            {
                printf(" ");
            }
            printf("%s", S[i]);
        }
        if (n != 0)
        {
            printf("\n");
        }
    }
}
int ContDigito(int l, int c, char S[l][c])
{
    int maior;
    for (int i = 0; i < l; i++)
    {
        if (i == 0 || (strlen(S[i]) - 1) > maior)
        {
            maior = (strlen(S[i]) - 1);
        }
    }
    return maior;
}
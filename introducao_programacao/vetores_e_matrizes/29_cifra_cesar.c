#include <stdio.h>
#include <string.h>
void Traduzir(int t, char S[t], int e);
int main()
{
    int n, e;
    char S[51];
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        fgets(S, 50, stdin);
        if (S[strlen(S) - 1] == '\n')
        {
            S[strlen(S) - 1] = '\0';
        }
        scanf("%d", &e);
        getchar();
        Traduzir(51, S, e);
        printf("%s\n", S);
    }
}
void Traduzir(int t, char S[t], int e)
{
    int sup;
    for (int i = 0; i < strlen(S); i++)
    {
        if (S[i] - e >= 'A')
        {
            S[i] = S[i] - e;
        }
        else
        {
            sup = e - (S[i] - ('A' - 1));
            S[i] = 'Z' - sup;
        }
    }
}
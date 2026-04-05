#include <stdio.h>
#include <string.h>

int main()
{
    int n, bandeira = 0;
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
        for (int j = 0; j < strlen(S); j++)
        {
            if ((j == 0 && S[j] != ' '))
            {
                printf("%c", S[j]);
            }
            if (S[j] == ' ')
            {
                bandeira = 1;
            }
            else if (bandeira == 1)
            {
                printf("%c", S[j]);
                bandeira = 0;
            }
        }
    }
}
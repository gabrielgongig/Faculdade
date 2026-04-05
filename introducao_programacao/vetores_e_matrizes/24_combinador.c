#include <stdio.h>
#include <string.h>

int main()
{
    int n, menor;
    char S[51], S2[51];
    scanf("%d", &n);
    getchar();

    for (int i = 1; i <= n; i++)
    {
        fgets(S, 50, stdin);
        fgets(S2, 50, stdin);

        if (S[strlen(S) - 1] == '\n')
        {
            S[strlen(S) - 1] = '\0';
        }
        if (S2[strlen(S2) - 1] == '\n')
        {
            S2[strlen(S2) - 1] = '\0';
        }

        if (strlen(S) <= strlen(S2))
        {
            menor = strlen(S);
        }
        else
        {
            menor = strlen(S2);
        }

        for (int j = 0; j < menor; j++)
        {
            printf("%c", S[j]);
            printf("%c", S2[j]);
        }

        if (menor == strlen(S))
        {
            for (int j = menor; j < strlen(S2); j++)
            {
                printf("%c", S2[j]);
            }
        }
        else
        {
            for (int j = menor; j < strlen(S); j++)
            {
                printf("%c", S[j]);
            }
        }

        printf("\n");
    }

    return 0;
}
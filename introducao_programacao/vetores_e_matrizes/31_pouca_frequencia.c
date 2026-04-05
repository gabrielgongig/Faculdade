#include <stdio.h>
#include <string.h>

int main()
{
    int n, t, soma = 0, ct = 0;
    float media, Media[100];
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        char estudantes[5100], presenca[5100];
        scanf("%d", &t);
        getchar();
        fgets(estudantes, 5099, stdin);
        fgets(presenca, 5099, stdin);
        for (int j = 1; j < t; j++)
        {
            soma = 0;
            ct = 0;
            int ct2 = 0;
            for (int k = 0; k < strlen(presenca); k++)
            {
                if (presenca[k] == 'P')
                {
                    soma++;
                }
                if (presenca[k] == 'P' || presenca[k] == 'A')
                {
                    ct++;
                }
                else if (presenca[k] == ' ')
                {
                    media = soma / (ct * 1.0);
                    Media[ct2] = media;
                    soma = 0;
                    ct = 0;
                }
            }
            ct = 0;
            for (int k = 0; k < strlen(estudantes); k++)
            {
                if (estudantes[k] == ' ')
                {
                    ct++;
                }
                if (Media[ct] < 7.5)
                {
                    printf("%c", estudantes[k]);
                }
            }
        }
    }
}
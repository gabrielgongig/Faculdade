#include <stdio.h>
#include <string.h>

void caixaalta(char s[]);

int main()
{
    char s[301];
    fgets(s, 300, stdin);

    caixaalta(s);
    printf("%s", s);

    return 0;
}

void caixaalta(char s[])
{
    int troca = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' && troca == 1)
        {
            s[i] -= 32;
            troca = 0;
        }
        else
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                if (troca == 1)
                {
                    troca = 0;
                }
                else
                {
                    s[i] += 32;
                }
            }
            else if (s[i] == ' ')
            {
                troca = 1;
            }
        }
    }
}
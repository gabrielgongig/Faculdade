#include <stdio.h>
#include <string.h>

void formatar(int t, char s[t]);

int main()
{
    char s[51];
    fgets(s, 50, stdin);
    while (s[1] != '\0')
    {
        formatar(51, s);
        printf("%s", s);
        fgets(s, 50, stdin);
    }
    return 0;
}

void formatar(int t, char s[t])
{
    int ct = 1;
    int tamanho = strlen(s);
    for (int i = 0; i < tamanho; i++)
    {
        if (ct % 2 != 0 && s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
        else if (ct % 2 == 0 && s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] + 32;
        }
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            ct++;
        }
    }
}
#include <stdio.h>
#include <string.h>

void Formatar(int t, char S[t], int t2, char Suporte[t2]);

int main()
{
    char S[51], Suporte[200];
    fgets(S, 50, stdin);
    while (S[1] != '\0')
    {
        if (S[strlen(S) - 1] == '\n')
        {
            S[strlen(S) - 1] = '\0';
        }
        Formatar(51, S, 200, Suporte);
        printf("%s\n", Suporte);
        fgets(S, 50, stdin);
    }
}
void Formatar(int t, char S[t], int t2, char Suporte[t2])
{
    int htmn = 0, htmi = 0, ct = 0;
    for (int i = 0; i < strlen(S); i++)
    {
        if (S[i] == '_' && htmi == 0)
        {
            Suporte[ct] = '<';
            Suporte[ct + 1] = 'i';
            Suporte[ct + 2] = '>';
            htmi = 1;
            ct += 3;
        }
        else if (S[i] == '_' && htmi == 1)
        {
            Suporte[ct] = '<';
            Suporte[ct + 1] = '/';
            Suporte[ct + 2] = 'i';
            Suporte[ct + 3] = '>';
            htmi = 0;
            ct += 4;
        }
        else if (S[i] == '*' && htmn == 0)
        {
            Suporte[ct] = '<';
            Suporte[ct + 1] = 'b';
            Suporte[ct + 2] = '>';
            htmn = 1;
            ct += 3;
        }
        else if (S[i] == '*' && htmn == 1)
        {
            Suporte[ct] = '<';
            Suporte[ct + 1] = '/';
            Suporte[ct + 2] = 'b';
            Suporte[ct + 3] = '>';
            htmn = 0;
            ct += 4;
        }
        else
        {
            Suporte[ct] = S[i];
            ct++;
        }
    }
    Suporte[ct + 1] = '\0';
}
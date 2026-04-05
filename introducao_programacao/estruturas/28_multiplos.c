#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, razao;
    scanf("%d%d", &a, &b);
    if (a > b)
    {
        razao = a % b;
    }
    else
    {
        razao = b % a;
    }

    if (razao == 0)
    {
        printf("Sao Multiplos\n");
    }
    else
    {
        printf("Nao sao Multiplos\n");
    }
}
#include <stdio.h>

int main()
{
    int a, b, c, d, e, par = 0, impar = 0, p = 0, n = 0;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    if (a % 2 == 0)
    {
        par++;
    }
    if (b % 2 == 0)
    {
        par++;
    }
    if (c % 2 == 0)
    {
        par++;
    }
    if (d % 2 == 0)
    {
        par++;
    }
    if (e % 2 == 0)
    {
        par++;
    }

    if (a % 2 != 0)
    {
        impar++;
    }
    if (b % 2 != 0)
    {
        impar++;
    }
    if (c % 2 != 0)
    {
        impar++;
    }
    if (d % 2 != 0)
    {
        impar++;
    }
    if (e % 2 != 0)
    {
        impar++;
    }

    if (a > 0)
    {
        p++;
    }
    if (b > 0)
    {
        p++;
    }
    if (c > 0)
    {
        p++;
    }
    if (d > 0)
    {
        p++;
    }
    if (e > 0)
    {
        p++;
    }

    if (a < 0)
    {
        n++;
    }
    if (b < 0)
    {
        n++;
    }
    if (c < 0)
    {
        n++;
    }
    if (d < 0)
    {
        n++;
    }
    if (e < 0)
    {
        n++;
    }

    printf("%d valor(es) par(es)\n", par);
    printf("%d valor(es) impar(es)\n", impar);
    printf("%d valor(es) positivo(s)\n", p);
    printf("%d valor(es) negativo(s)\n", n);
}
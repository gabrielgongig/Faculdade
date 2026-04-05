#include <stdio.h>

int main()
{
    int n, x, i = 1, i2 = 2, y = 0; /*i->quantidade de testes; i2->testagem de cada numero; y="boolean" que identifica
          se x e primo*/
    scanf("%d", &n);

    while (i <= n)
    {
        scanf("%d", &x);
        while (i2 < x)
        {
            if (x % i2 == 0)
            {
                y = 1;
            }
            i2++;
        }
        if (y == 0)
        {
            printf("%d eh primo\n", x);
        }
        else if (y == 1)
        {
            printf("%d nao eh primo\n", x);
        }
        y = 0;
        i2 = 2;
        i++;
    }
}
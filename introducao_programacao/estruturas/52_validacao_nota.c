#include <stdio.h>

int main()
{
    float x, y, media;
    int val = 0;

    while (val == 0)
    {
        scanf("%f", &x);
        if (x >= 0.0 && x <= 10.0)
        {
            val = 1;
        }
        else
        {
            printf("nota invalida\n");
        }
    }

    while (val == 1)
    {
        scanf("%f", &y);
        if (y >= 0.0 && y <= 10.0)
        {
            val = 2;
        }
        else
        {
            printf("nota invalida\n");
        }
    }
    media = (x + y) / 2;
    printf("media = %.2f\n", media);
}
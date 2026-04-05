#include <stdio.h>

int main()
{
    int x, y, soma = 0;
    scanf("%d", &x);
    scanf("%d", &y);

    if (x >= y)
    {
        y++;
        while (y < x)
        {
            if (y % 2 != 0)
            {
                soma += y;
            }
            y++;
        }
    }
    else if (y > x)
    {
        x++;
        while (x < y)
        {
            if (x % 2 != 0)
            {
                soma += x;
            }
            x++;
        }
    }
    printf("%d\n", soma);
}
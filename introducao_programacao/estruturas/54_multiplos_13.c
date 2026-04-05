#include <stdio.h>

int main()
{
    int x, y, soma = 0;
    scanf("%d", &x);
    scanf("%d", &y);

    if (x >= y)
    {
        while (y <= x)
        {
            if (y % 13 != 0)
            {
                soma += y;
            }
            y++;
        }
    }
    else if (y > x)
    {
        while (x <= y)
        {
            if (x % 13 != 0)
            {
                soma += x;
            }
            x++;
        }
    }
    printf("%d\n", soma);
}
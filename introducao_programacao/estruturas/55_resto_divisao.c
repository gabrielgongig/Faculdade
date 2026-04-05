#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    if (x >= y)
    {
        y++;
        while (y < x)
        {
            if (y % 5 == 2 || y % 5 == 3)
            {
                printf("%d\n", y);
            }
            y++;
        }
    }
    else if (y > x)
    {
        x++;
        while (x < y)
        {
            if (x % 5 == 2 || x % 5 == 3)
            {
                printf("%d\n", x);
            }
            x++;
        }
    }
}
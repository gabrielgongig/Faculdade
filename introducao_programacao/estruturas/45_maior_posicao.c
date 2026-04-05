#include <stdio.h>

int main()
{
    int i = 1, n, x = 0, y;
    while (i <= 100)
    {
        scanf("%d", &n);
        if (n > x)
        {
            x = n;
            y = i;
        }
        i++;
    }
    printf("%d\n%d\n", x, y);
}
#include <stdio.h>

int main()
{
    int x, i = 6;
    scanf("%d", &x);

    while (i > 0)
    {
        if (x % 2 != 0)
        {
            printf("%d\n", x);
            i--;
        }
        x++;
    }
}
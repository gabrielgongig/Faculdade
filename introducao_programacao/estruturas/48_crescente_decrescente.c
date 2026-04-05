#include <stdio.h>

int main()
{
    int x = 1, y = 2;

    while (x != y)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        if (x > y)
        {
            printf("Decrescente\n");
        }
        else if (y > x)
        {
            printf("Crescente\n");
        }
    }
}
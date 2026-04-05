#include <stdio.h>

int main()
{
    int x, y, i = 1;
    scanf("%d%d", &x, &y);

    while (i <= y)
    {
        printf("%d", i);

        if (i % x == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
        i++;
    }
}
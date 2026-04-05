#include <stdio.h>

int main()
{
    int x = 0, y = 1, n, i = 1, z = 0;
    scanf("%d", &n);
    n = n - 2;
    printf("0 1 ");
    while (i <= n)
    {
        z = x + y;
        printf("%d", z);
        if (i < n)
        {
            printf(" ");
        }
        else if (i == n)
        {
            printf("\n");
        }
        x = y;
        y = z;
        i++;
    }
}
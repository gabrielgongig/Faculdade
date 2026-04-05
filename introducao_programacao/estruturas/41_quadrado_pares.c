#include <stdio.h>

int main()
{
    int n, q, i = 1;
    scanf("%d", &n);
    while (i <= n)
    {
        if (i % 2 == 0)
        {
            q = i * i;
            printf("%d^2 = %d\n", i, q);
        }
        i++;
    }
    return 0;
}
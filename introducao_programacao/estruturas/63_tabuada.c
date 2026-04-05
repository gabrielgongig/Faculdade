#include <stdio.h>

int main()
{
    int n, i = 1, prod;
    scanf("%d", &n);

    while (i <= 10)
    {
        prod = i * n;
        printf("%d x %d = %d\n", i, n, prod);
        i++;
    }
}
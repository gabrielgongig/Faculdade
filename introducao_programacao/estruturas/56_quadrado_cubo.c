#include <stdio.h>

int main()
{
    int n, i = 1, q, c;
    scanf("%d", &n);

    while (i <= n)
    {
        q = i * i;
        c = i * i * i;
        printf("%d %d %d\n", i, q, c);
        i++;
    }
}
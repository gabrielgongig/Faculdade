#include <stdio.h>
#define t 10
int main()
{
    int n[t], i = 0, x;
    scanf("%d", &x);
    n[0] = x;
    for (i = 1; i < t; i++)
    {
        n[i] = n[i - 1] * 2;
    }
    for (i = 0; i < t; i++)
    {
        printf("N[%d] = %d\n", i, n[i]);
    }
}
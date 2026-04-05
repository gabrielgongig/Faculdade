#include <stdio.h>
int main()
{
    int n, sup, x;
    long long int F[60];
    scanf("%d", &x);
    for (int j = 0; j < x; j++)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            printf("Fib(0) = 0\n");
        }
        else if (n == 1)
        {
            printf("Fib(1) = 1\n");
        }
        else
        {
            F[0] = 0;
            F[1] = 1;
            for (int i = 2; i <= n; i++)
            {
                F[i] = F[i - 1] + F[i - 2];
            }
            printf("Fib(%d) = %lld\n", n, F[n]);
        }
    }
}
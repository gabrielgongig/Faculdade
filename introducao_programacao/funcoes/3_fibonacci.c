#include <stdio.h>

int Fibonacci(int i);

int main()
{
    int i = 1, n, fib;

    scanf("%d", &n);
    if (n > 0)
    {
        printf("0 ");
    }
    if (n > 1)
    {
        printf("1 ");
    }
    n = n - 2;
    while (i <= n)
    {
        fib = Fibonacci(i);
        printf("%d ", fib);
        i++;
    }
}

int Fibonacci(int i)
{
    int a = 1, b = 2, i2 = 1, fib;
    while (i2 < i)
    {
        fib = a;
        a = b;
        b = fib + a;
        i2++;
    }
    return a;
}
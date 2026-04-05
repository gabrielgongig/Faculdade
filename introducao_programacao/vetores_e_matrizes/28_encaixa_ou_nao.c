#include <stdio.h>

int main()
{
    long long int a, b;
    int n, x = 0;
    scanf("%d", &n);
    // n=1;
    for (int i = 1; i <= n; i++)
    {
        x = 0;
        scanf("%lld%lld", &a, &b);
        // a=436456454536;
        // b=6;
        if (a < b)
        {
            printf("nao encaixa\n");
        }
        else if (b < 10)
        {
            if ((a % 10) == b)
            {
                printf("encaixa\n");
            }
            else
            {
                printf("nao encaixa\n");
            }
        }
        else
        {
            while (b >= 10)
            {
                if (b % 10 == a % 10)
                {
                    b = b / 10;
                    a = a / 10;
                }
                else
                {
                    x = 1;
                    b = 0;
                }
            }
            if (x == 0 && b == a % 10)
            {
                printf("encaixa\n");
            }
            else
            {
                printf("nao encaixa\n");
            }
        }
    }
    return 0;
}
#include <stdio.h>

int main()
{
    int m = 1, n = 1, sum = 0;
    while (m > 0 && n > 0)
    {
        scanf("%d", &m);
        scanf("%d", &n);
        if (m > 0 && n > 0)
        {
            if (m == n)
            {
                printf("%d Sum=%d\n", m, m);
            }
            else if (m > n)
            {
                while (n <= m)
                {
                    printf("%d ", n);
                    sum += n;
                    n++;
                }
                printf("Sum=%d\n", sum);
            }

            else if (n > m)
            {
                while (m <= n)
                {
                    printf("%d ", m);
                    sum += m;
                    m++;
                }
                printf("Sum=%d\n", sum);
            }
            sum = 0;
        }
    }
}
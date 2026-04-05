#include <stdio.h>

int main()
{
    int n, i = 1;
    float x, y, res;
    scanf("%d", &n);

    while (i <= n)
    {
        scanf("%f", &x);
        scanf("%f", &y);
        if (y == 0)
        {
            printf("divisao impossivel\n");
        }
        else
        {
            res = x / y;
            printf("%.1f\n", res);
        }
        i++;
    }
}
#include <stdio.h>

int main()
{

    double N[100], x;
    scanf("%lf", &x);
    N[0] = x;
    printf("N[0] = %.4lf\n", x);
    for (int i = 1; i < 100; i++)
    {
        N[i] = x / 2;
        x = N[i];
        printf("N[%d] = %.4lf\n", i, N[i]);
    }
}

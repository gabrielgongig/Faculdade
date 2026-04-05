#include <stdio.h>
#include <math.h>
int ContarDigito(int n);
int main()
{
    int n = 1, M[15][15], ct = 0, d_maior, d;
    while (n != 0)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            ct = i;
            for (int j = 0; j < n; j++)
            {
                M[i][j] = pow(2, ct);
                ct++;
            }
        }
        d_maior = ContarDigito(M[n - 1][n - 1]);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d = ContarDigito(M[i][j]);
                if (j == 0)
                {
                    for (int k = 0; k < (d_maior - d); k++)
                    {
                        printf(" ");
                    }
                }
                else
                {
                    for (int k = 0; k < ((d_maior + 1) - d); k++)
                    {
                        printf(" ");
                    }
                }
                printf("%d", M[i][j]);
            }
            printf("\n");
        }
        if (n != 0)
        {
            printf("\n");
        }
    }
}
int ContarDigito(int n)
{
    int ct = 0;
    while (n >= 1)
    {
        n = n / 10;
        ct++;
    }
    return ct;
}
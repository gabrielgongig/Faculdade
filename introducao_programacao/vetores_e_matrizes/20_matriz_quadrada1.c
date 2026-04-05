#include <stdio.h>

int main()
{
    int n = 1, M[100][100], ct = 1;

    while (n != 0)
    {
        scanf("%d", &n);
        for (int k = 0; k < (n / 2) + 1; k++)
        {
            for (int i = k; i < (n - k); i++)
            {
                for (int j = k; j < (n - k); j++)
                {
                    M[i][j] = ct;
                }
            }
            ct++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == n - 1)
                {
                    printf("%3d", M[i][j]);
                }
                else
                {
                    printf("%3d ", M[i][j]);
                }
            }
            printf("\n");
        }
        if (n != 0)
        {
            printf("\n");
        }
        ct = 1;
    }
}
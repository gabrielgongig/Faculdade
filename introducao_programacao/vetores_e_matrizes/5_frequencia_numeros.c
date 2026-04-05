#include <stdio.h>

int main()
{
    int n, ct = 0;
    scanf("%d", &n);
    int M[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &M[i]);
    }
    for (int j = 1; j <= 2000; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j == M[i])
            {
                ct++;
            }
        }
        if (ct != 0)
        {
            printf("%d aparece %d vez(es)\n", j, ct);
        }
        ct = 0;
    }
}
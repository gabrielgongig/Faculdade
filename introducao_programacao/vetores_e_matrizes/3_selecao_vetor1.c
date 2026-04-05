#include <stdio.h>
#define t 100
int main()
{
    float A[t];

    for (int i = 0; i < t; i++)
    {
        scanf("%f", &A[i]);
    }
    for (int i = 0; i < t; i++)
    {
        if (A[i] <= 10)
        {
            printf("A[%d] = %.1f\n", i, A[i]);
        }
    }
}

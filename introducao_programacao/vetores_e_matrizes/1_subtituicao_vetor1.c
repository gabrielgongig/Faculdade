#include <stdio.h>
#define t 10
int main()
{
    int x[t], i = 0;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &x[i]);
    }
    for (i = 0; i < 10; i++)
    {
        if (x[i] <= 0)
        {
            x[i] = 1;
        }
        printf("X[%d] = %d\n", i, x[i]);
    }
}

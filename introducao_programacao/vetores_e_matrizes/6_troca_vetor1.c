#include <stdio.h>

int main()
{

    int N[20], sup, j = 19;
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &N[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        sup = N[i];
        N[i] = N[j];
        N[j] = sup;
        j--;
    }

    for (int i = 0; i < 20; i++)
    {
        printf("N[%d] = %d\n", i, N[i]);
    }
}
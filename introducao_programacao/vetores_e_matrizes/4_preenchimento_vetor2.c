#include <stdio.h>

int main()
{
    int N[1000], t, ct = 0;
    scanf("%d", &t);

    for (int i = 0; i < 1000; i++)
    {
        if (ct == t)
        {
            ct = 0;
        }
        N[i] = ct;
        printf("N[%d] = %d\n", i, N[i]);
        ct++;
    }
}

#include <stdio.h>
#define t 5
int main()
{
    int impar[t], par[t], ctp = 0, cti = 0, x;
    for (int i = 0; i < 15; i++)
    {
        scanf("%d", &x);
        if (x % 2 == 0)
        {
            par[ctp] = x;
            ctp++;
        }
        else if (x % 2 != 0)
        {
            impar[cti] = x;
            cti++;
        }
        if (ctp == t)
        {
            for (int i = 0; i < t; i++)
            {
                printf("par[%d] = %d\n", i, par[i]);
            }
            ctp = 0;
        }
        if (cti == t)
        {
            for (int i = 0; i < t; i++)
            {
                printf("impar[%d] = %d\n", i, impar[i]);
            }
            cti = 0;
        }
    }
    for (int i = 0; i < cti; i++)
    {
        printf("impar[%d] = %d\n", i, impar[i]);
    }
    for (int i = 0; i < ctp; i++)
    {
        printf("par[%d] = %d\n", i, par[i]);
    }

    return 0;
}

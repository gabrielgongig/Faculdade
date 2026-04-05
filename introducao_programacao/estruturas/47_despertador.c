#include <stdio.h>

int main()
{
    int hora1, min1, hora2, min2, s = 0, dhora, dmin;

    while (s == 0)
    {

        scanf("%d%d%d%d", &hora1, &min1, &hora2, &min2);
        if (hora1 == hora2)
        {
            if (min2 > min1)
            {
                dhora = 0;
                dmin = min2 - min1;
            }
            else if (min1 > min2)
            {
                dhora = 23;
                dmin = (60 - min1) + min2;
            }
            else if (min1 == min2)
            {
                dhora = 24;
                dmin = 0;
            }
        }
        if (hora2 > hora1)
        {
            if (min2 > min1)
            {
                dhora = hora2 - hora1;
                dmin = min2 - min1;
            }
            else if (min1 > min2)
            {
                dhora = hora2 - hora1 - 1;
                dmin = (60 - min1) + min2;
            }
            else if (min1 == min2)
            {
                dhora = hora2 - hora1;
                dmin = 0;
            }
        }
        if (hora1 > hora2)
        {
            if (min2 > min1)
            {
                dhora = (24 - hora1) + hora2;
                dmin = min2 - min1;
            }
            else if (min1 > min2)
            {
                dhora = (24 - hora1) + hora2 - 1;
                dmin = (60 - min1) + min2;
            }
            else if (min1 == min2)
            {
                dhora = (24 - hora1) + hora2;
                dmin = 0;
            }
        }

        if (hora1 == 0 && hora1 == 0 && min1 == 0 && min2 == 0)
        {
            s = 1;
        }

        int s2 = (dhora * 60) + dmin;

        if (s == 0)
        {
            printf("%d\n", s2);
        }
    }
}
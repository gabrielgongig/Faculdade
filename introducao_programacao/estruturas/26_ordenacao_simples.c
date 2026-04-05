#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c, x, y, z;
    scanf("%d%d%d", &a, &b, &c);
    if (a < b && a < c)
    {
        x = a;
    }
    else if (b < a && b < c)
    {
        x = b;
    }
    else if (c < a && c < b)
    {
        x = c;
    }

    if (a > b && a > c)
    {
        z = a;
    }
    else if (b > a && b > c)
    {
        z = b;
    }
    else if (c > a && c > b)
    {
        z = c;
    }

    if (a != x && a != z)
    {
        y = a;
    }
    else if (b != x && b != z)
    {
        y = b;
    }
    else if (c != x && c != z)
    {
        y = c;
    }
    printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", x, y, z, a, b, c);
}
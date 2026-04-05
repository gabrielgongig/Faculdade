#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, x, y, z;
    scanf("%lf%lf%lf", &a, &b, &c);

    if (a > b && a > c)
    {
        x = a;
    }
    if (b > a && b > c)
    {
        x = b;
    }
    if (c > b && c > a)
    {
        x = c;
    }
    if (a < b && a < c)
    {
        z = a;
    }
    if (b < a && b < c)
    {
        z = b;
    }
    if (c < b && c < a)
    {
        z = c;
    }
    if (a > b && a == c)
    {
        x = a;
        y = c;
        z = b;
    }
    if (a > c && a == b)
    {
        x = a;
        y = b;
        z = c;
    }

    if (b > a && b == c)
    {
        x = b;
        y = c;
        z = a;
    }
    if (b > c && b == a)
    {
        x = a;
        y = b;
        z = c;
    }

    if (c > a && c == b)
    {
        x = b;
        y = c;
        z = a;
    }
    if (c > b && c == a)
    {
        x = a;
        y = c;
        z = b;
    }
    if (a == b && a == c)
    {
        x = a;
        y = b;
        z = b;
    }
    if (a > b && a < c)
    {
        y = a;
    }
    if (a < b && a > c)
    {
        y = a;
    }
    if (b > a && b < c)
    {
        y = b;
    }
    if (b > c && b < a)
    {
        y = b;
    }
    if (c > b && c < a)
    {
        y = c;
    }
    if (c > a && c < b)
    {
        y = c;
    }
    if (a < b && a == c)
    {
        x = b;
        y = a;
        z = c;
    }
    if (a < c && a == b)
    {
        x = c;
        y = a;
        z = b;
    }
    if (b < a && b == c)
    {
        x = a;
        y = c;
        z = b;
    }
    if (b < c && b == a)
    {
        x = c;
        y = a;
        z = b;
    }
    if (c < a && c == b)
    {
        x = a;
        y = c;
        z = b;
    }
    if (c < b && c == a)
    {
        x = b;
        y = a;
        z = c;
    }

    if (x >= (y + z))
    {
        printf("NAO FORMA TRIANGULO\n");
    }
    else
    {
        if ((x * x) == (y * y) + (z * z))
        {
            printf("TRIANGULO RETANGULO\n");
        }
        if ((x * x) > (y * y) + (z * z))
        {
            printf("TRIANGULO OBTUSANGULO\n");
        }
        if ((x * x) < (y * y) + (z * z))
        {
            printf("TRIANGULO ACUTANGULO\n");
        }

        if (x == y && x == z && y == z)
        {
            printf("TRIANGULO EQUILATERO\n");
        }
        else if (x == y || y == z || x == z)
        {
            printf("TRIANGULO ISOSCELES\n");
        }
    }
}
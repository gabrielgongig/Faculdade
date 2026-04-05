#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, per, area;
    scanf("%f%f%f", &a, &b, &c);

    if ((a + b) > c && (a + c) > b && (b + c) > a)
    {
        per = a + b + c;
        printf("Perimetro = %.1f\n", per);
    }
    else
    {
        area = ((a + b) * c) / 2;
        printf("Area = %.1f\n", area);
    }
    return 0;
}

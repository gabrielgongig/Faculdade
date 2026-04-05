#include <stdio.h>

int main()
{
    float c;
    float k;
    float f;

    scanf("%f", &c);
    k = c + 273;
    f = k * 1.8 - 459.4;

    printf("celsius : %f\nkelvin : % f\nfahrenheit : % f", c, k, f);

    return 0;
}
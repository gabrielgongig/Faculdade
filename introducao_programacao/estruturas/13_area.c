#include <stdio.h>

int main()
{
    double a, b, c, Atriangulo, Acirculo, Atrapezio, Aquadrado, Aretangulo;
    scanf("%lf%lf%lf", &a, &b, &c);
    Atriangulo = (a * c) / 2;
    Acirculo = 3.14159 * c * c;
    Atrapezio = ((a + b) * c) / 2;
    Aquadrado = b * b;
    Aretangulo = a * b;
    printf("TRIANGULO: %.3lf\nCIRCULO: %.3lf\nTRAPEZIO: %.3lf\nQUADRADO: %.3lf\nRETANGULO: %.3lf\n", Atriangulo, Acirculo, Atrapezio, Aquadrado, Aretangulo);
    return 0;
}
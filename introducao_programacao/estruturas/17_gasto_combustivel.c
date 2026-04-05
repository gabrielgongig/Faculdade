#include <stdio.h>
#include <math.h>
int main()
{
    int horas, v;
    float dist, litros;
    scanf("%d%d", &horas, &v);
    dist = v * horas;
    litros = dist / 12;
    printf("%.3f\n", litros);

    return 0;
}
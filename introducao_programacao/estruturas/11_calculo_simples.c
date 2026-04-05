#include <stdio.h>
#include <math.h>
int main()
{
    int cod1, q1, cod2, q2;
    float p1, p2, pf;
    scanf("%d%d%f%d%d%f", &cod1, &q1, &p1, &cod2, &q2, &p2);
    pf = q1 * p1 + q2 * p2;
    printf("VALOR A PAGAR: R$ %.2f\n", pf);
    return 0;
}
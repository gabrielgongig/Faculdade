#include <stdio.h>
#include <math.h>

double taylor_ln(double x, double precision)
{
    double term = x;
    double sum = term;
    int n = 2;

    while (fabs(term) > precision)
    {
        term = pow(-1, n + 1) * pow(x, n) / n;
        sum += term;
        n++;
    }

    return sum;
}

int main()
{
    double x, precision;

    printf("Digite o valor de x (entre -1 e 1): ");
    scanf("%lf", &x);
    printf("Digite a precisao desejada: ");
    scanf("%lf", &precision);

    double result = taylor_ln(x, precision);
    printf("Aproximacao de ln(1 + %.2f): %.10f\n", x, result);

    double actual = log(1 + x);
    printf("Valor exato com log: %.10f\n", actual);
    printf("Erro absoluto: %.10f\n", fabs(actual - result));

    return 0;
}
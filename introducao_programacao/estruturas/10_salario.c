#include <stdio.h>

int main()
{
    int n, horas;
    float dinheiro, salario;
    scanf("%d%d%f", &n, &horas, &dinheiro);
    salario = dinheiro * horas;
    printf("NUMBER = %d\nSALARY = U$ %.2f\n", n, salario);

    return 0;
}
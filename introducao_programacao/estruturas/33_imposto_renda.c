#include <stdio.h>

int main()
{
    float salario, imposto = 0;
    scanf("%f", &salario);

    if (salario > 4500)
    {
        salario = salario - 4500;
        imposto = 350 + salario * 0.28;
        printf("R$ %.2f\n", imposto);
    }
    else if (salario >= 3000.01 && salario <= 4500)
    {
        salario = salario - 3000;
        imposto = 80 + 0.18 * salario;
        printf("R$ %.2f\n", imposto);
    }
    else if (salario >= 2000.01 && salario <= 3000)
    {
        salario = salario - 2000;
        imposto = salario * 0.08;
        printf("R$ %.2f\n", imposto);
    }
    else if (salario <= 2000)
    {
        printf("Isento\n");
    }
}
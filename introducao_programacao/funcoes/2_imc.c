#include <stdio.h>

float calcular(float peso, float altura);
void inf(float x);

int main()
{
    float p, h, imc;

    scanf("%f%f", &p, &h);

    imc = calcular(p, h);

    inf(imc);

    return 0;
}

float calcular(float peso, float altura)
{
    return (peso) / (altura * altura);
}
void inf(float x)
{

    if (x <= 18.5)
    {
        printf("Abaixo do peso\n");
    }
    else if (x > 18.5 && x <= 25)
    {
        printf("Normal\n");
    }
    else if (x > 25 && x <= 30)
    {
        printf("Sobrepeso\n");
    }
    else if (x > 30 && x <= 40)
    {
        printf("Obesidade\n");
    }
    else if (x > 40)
    {
        printf("Obesidade grave\n");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tam 11

long double Function(int t, float Coefs[], int grau, long double x)
{
    long double r = 0;
    for (int i = 0; i <= grau; i++)
    {
        r += Coefs[i] * pow(x, i);
    }
    return r;
}
long double Derivada(int t, float Coefs[], int grau, long double x)
{
    long double r = 0;
    for (int i = 1; i <= grau; i++)
    {
        r += Coefs[i] * i * pow(x, i - 1);
    }
    return r;
}

long double Bissecao(int t, float Coefs[], long double a, long double b, long double precisao, int *it, int grau)
{
    long double x, sup;
    int mode = 0;
    if (Function(t, Coefs, grau, a) * Function(t, Coefs, grau, b) < 0)
    {
        if (Function(t, Coefs, grau, b) < 0)
        {
            mode = 1;
        }
        while (fabs(b - a) > precisao && *it <= 20)
        {
            x = (a + b) / 2;
            printf("a = %Lf, b = %Lf, x=%Lf, i = %d\n", a, b, x, *it);
            (*it)++;
            if (Function(t, Coefs, grau, x) < 0)
            {
                if (mode == 0)
                {
                    a = x;
                }
                else if (mode == 1)
                {
                    b = x;
                }
            }
            else if (Function(t, Coefs, grau, x) > 0)
            {
                if (mode == 0)
                {
                    b = x;
                }
                else if (mode == 1)
                {
                    a = x;
                }
            }
        }
        printf("a = %Lf, b = %Lf, x=%Lf, i = %d\n", a, b, x, *it);
        return x;
    }
}

long double Newton(int t, float Coefs[], long double x, long double precisao, int *it, int grau)
{
    while ((fabs(Function(t, Coefs, grau, x)) > precisao) && *it <= 20)
    {
        printf("x%d=%Lf\n", *it, x);
        x = x - (Function(t, Coefs, grau, x) / Derivada(t, Coefs, grau, x));
        (*it)++;
    }
    printf("x%d=%Lf\n", *it, x);
    return x;
}

long double Secante(int t, float Coefs[], long double x0, long double x1, long double precisao, int *it, int grau)
{
    long double x2;
    if (*it == 0)
    {
        printf("x%d=%Lf\n", *it, x0);
        ;
    }
    while ((fabs(Function(t, Coefs, grau, x1)) > precisao) && *it <= 20)
    {
        printf("x%d=%Lf\n", *it + 1, x1);
        x2 = x1 - (Function(t, Coefs, grau, x1) * (x1 - x0)) / (Function(t, Coefs, grau, x1) - Function(t, Coefs, grau, x0));
        x0 = x1;
        x1 = x2;
        (*it)++;
    }
    printf("x%d=%Lf\n", *it + 1, x1);
    return x1;
}

int main()
{
    int opcao = 38, grau, it = 0;
    long double precisao;
    float Coefs[tam];

    while (opcao != 0)
    {
        printf("Escolha o metodo a ser utilizado:\n");
        printf("0 - Sair\n");
        printf("1 - Metodo da Bissecao\n");
        printf("2 - Metodo de Newton-Raphson\n");
        printf("3 - Metodo da Secante\n");
        scanf("%d", &opcao);
        while (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3)
        {
            printf("OPCAO INVALIDA\n");
            printf("Escolha o metodo a ser utilizado:\n");
            printf("0 - Sair\n");
            printf("1 - Metodo da Bissecao\n");
            printf("2 - Metodo de Newton-Raphson\n");
            printf("3 - Metodo da Secante\n");
            scanf("%d", &opcao);
        }
        if (opcao == 0)
        {
            break;
        }
        else
        {
            printf("Escolha o grau da funcao polinomial: ");
            scanf("%d", &grau);
            while (grau > 10 || grau <= 0)
            {
                printf("ESCOLHA UM VALOR VALIDO: ");
                scanf("%d", &grau);
                printf("\n");
            }
            printf("\n");
            for (int i = 0; i <= grau; i++)
            {
                printf("Escolha o coeficiente que acompanha o termo de grau %d: ", i);
                scanf("%f", &Coefs[i]);
                printf("\n");
            }
            printf("Digite a precisao\n");
            scanf("%Lf", &precisao);
            switch (opcao)
            {
            case 1:
            {
                long double a, b, x;
                printf("Informe o a: ");
                scanf("%Lf", &a);
                printf("\n");
                printf("Informe o b: ");
                scanf("%Lf", &b);
                printf("\n");
                x = Bissecao(tam, Coefs, a, b, precisao, &it, grau);
                if (it > 0)
                {
                    if (it >= 20)
                    {
                        printf("O LIMITE DE ITERACOES FOI ATINGIDO\n");
                    }
                    printf("-----------------------------------------------------------------------------------------------------\n");
                    printf("O zero aproximado da funcao e %Lf, e foram necessarias %d iteracoes para chegar nesse resultado\n", x, it);
                    printf("-----------------------------------------------------------------------------------------------------\n");
                }
                else
                {
                    printf("-----------------------------------------------------------------------------------------------------\n");
                    printf("O INTERVALO NAO APRESENTA RAIZES OU ALGUM ERRO ACONTECEU, LOGO, A OPERACAO NAO PODE CONTINUAR\n");
                    printf("-----------------------------------------------------------------------------------------------------\n");
                }
                opcao = 38;
                it = 0;
                break;
            }
            case 2:
            {
                long double x, x0;
                printf("Informe o x0: ");
                scanf("%Lf", &x0);
                printf("\n");
                x = Newton(tam, Coefs, x0, precisao, &it, grau);
                if (it >= 20)
                {
                    printf("O LIMITE DE ITERACOES FOI ATINGIDO\n");
                }
                printf("-----------------------------------------------------------------------------------------------------\n");
                printf("O zero aproximado da funcao e %Lf, e foram necessarias %d iteracoes para chegar nesse resultado\n", x, it);
                printf("-----------------------------------------------------------------------------------------------------\n");
                opcao = 38;
                it = 0;
                break;
            }
            case 3:
            {
                long double x, x0, x1;
                printf("Informe o x0: ");
                scanf("%Lf", &x0);
                printf("Informe o x1: ");
                scanf("%Lf", &x1);
                printf("\n");
                x = Secante(tam, Coefs, x0, x1, precisao, &it, grau);
                if (it >= 20)
                {
                    printf("O LIMITE DE ITERACOES FOI ATINGIDO\n");
                }
                printf("-----------------------------------------------------------------------------------------------------\n");
                printf("O zero aproximado da funcao e %Lf, e foram necessarias %d iteracoes para chegar nesse resultado\n", x, it);
                printf("-----------------------------------------------------------------------------------------------------\n");
                opcao = 38;
                it = 0;
                break;
            }
            }
        }
    }
}
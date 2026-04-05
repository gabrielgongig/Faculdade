#include <stdio.h>

int main()
{
    int ddd;
    scanf("%d", &ddd);

    switch (ddd)
    {
    case 61:
        printf("Brasilia\n");
        break;

    case 71:
        printf("Salvador\n");
        break;

    case 11:
        printf("Sao Paulo\n");
        break;

    case 21:
        printf("Rio de Janeiro\n");
        break;

    case 32:
        printf("Juiz de Fora\n");
        break;

    case 19:
        printf("Campinas\n");
        break;

    case 27:
        printf("Vitoria\n");
        break;

    case 31:
        printf("Belo Horizonte\n");
        break;
    }
    if (ddd != 61 && ddd != 71 && ddd != 11 && ddd != 21 && ddd != 32 && ddd != 19 && ddd != 27 && ddd != 31)
    {
        printf("DDD nao cadastrado\n");
    }

    return 0;
}
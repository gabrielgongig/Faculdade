#include <stdio.h>
#include <math.h>
int main()
{
    float n1, n2, n3, n4, media, exame, final;
    scanf("%f%f%f%f", &n1, &n2, &n3, &n4);
    media = (2 * n1 + 3 * n2 + 4 * n3 + n4) / 10;
    if (media >= 7.0)
    {
        printf("Media: %.1f\nAluno aprovado.\n", media);
    }
    else if (media < 5.0)
    {
        printf("Media: %.1f\nAluno reprovado.\n", media);
    }
    else if (media >= 5.0 && media <= 6.9)
    {
        printf("Media: %.1f\nAluno em exame.\n", media);
        scanf("%f", &exame);
        printf("Nota do exame: %.1f\n", exame);
        final = (media + exame) / 2;
        if (final >= 5.0)
        {
            printf("Aluno aprovado.\n");
        }
        else if (final < 5.0)
        {
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1f\n", final);
    }
    return 0;
}
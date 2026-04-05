#include <stdio.h>

void maior(int *a, int *b, int *c);

int main()
{
    int n1, n2, n3;
    scanf("% d % d % d", &n1, &n2, &n3);

    maior(&n1, &n2, &n3);

    printf("% d\n % d\n % d\n", n1, n2, n3);

    return 0;
}
void maior(int *a, int *b, int *c)
{
    int aux = 0;
    if (*a > *b)
    {
        aux = *a;
        *a = *b;
        *b = aux;
    }
    if (*a > *c)
    {
        aux = *a;
        *a = *c;
        *c = aux;
    }
    if (*b > *c)
    {
        aux = *b;
        *b = *c;
        *c = aux;
    }
}
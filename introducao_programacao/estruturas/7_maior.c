#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c, maiorAB, maiorAB_C;
    scanf("%d%d%d", &a, &b, &c);
    maiorAB = (a + b + abs(a - b)) / 2;
    maiorAB_C = (maiorAB + c + abs(maiorAB - c)) / 2;
    printf("%d eh o maior\n", maiorAB_C);

    return 0;
}
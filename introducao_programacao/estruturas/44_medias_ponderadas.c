#include <stdio.h>

int main()
{
    int n, i = 1;
    float n1, n2, n3, media;
    scanf("%d", &n);
    while (i <= n)
    {
        scanf("%f", &n1);
        scanf("%f", &n2);
        scanf("%f", &n3);
        media = ((n1 * 2) + (n2 * 3) + (n3 * 5)) / 10;
        printf("%.1f\n", media);
        i++;
    }
    return 0;
}
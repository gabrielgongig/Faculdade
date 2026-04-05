#include <stdio.h>

int main()
{
    int km;
    float comb, media;

    scanf("%d%f", &km, &comb);
    media = km / comb;
    printf("%.3f km/l\n", media);
    return 0;
}
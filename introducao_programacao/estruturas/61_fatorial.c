#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int fat = 1;
    while (n > 1)
    {
        fat = fat * n;
        n--;
    }
    printf("%d\n", fat);
}
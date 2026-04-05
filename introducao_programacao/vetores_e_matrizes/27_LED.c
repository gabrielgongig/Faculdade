#include <stdio.h>
#include <math.h>
int main()
{
    int n, v, leds = 0, j = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int vetor[100];
        scanf("%d", &v);
        while (v >= 1)
        {
            vetor[j] = v % 10;
            v = v / 10;
            j++;
        }
        for (int k = 0; k < j; k++)
        {
            switch (vetor[k])
            {
            case 0:
                leds += 6;
                break;
            case 1:
                leds += 2;
                break;
            case 2:
                leds += 5;
                break;
            case 3:
                leds += 5;
                break;
            case 4:
                leds += 4;
                break;
            case 5:
                leds += 5;
                break;
            case 6:
                leds += 6;
                break;
            case 7:
                leds += 3;
                break;
            case 8:
                leds += 7;
                break;
            case 9:
                leds += 6;
                break;
            }
        }
        printf("%d leds\n", leds);
        leds = 0;

        j = 0;
    }
}
#include <stdio.h>

int main()
{
    int hi, mi, hf, mf, H, M, res, deltaH, deltaM;
    scanf("%d%d%d%d", &hi, &mi, &hf, &mf);

    if (hf > hi || (hf == hi && mf > mi))
    {
        deltaH = hf - hi;
        res = (deltaH * 60) - mi + mf;
        H = res / 60;
        M = res % 60;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", H, M);
    }
    else if (hf == hi && mf == mi)
    {
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
    }
    else if (hi > hf || (hf == hi && mf < mi))
    {
        deltaH = (24 - hi) + hf;
        res = (deltaH * 60) - mi + mf;
        H = res / 60;
        M = res % 60;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", H, M);
    }
    return 0;
}
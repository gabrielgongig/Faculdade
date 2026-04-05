#include <stdio.h>

int main()
{
    int n, x, i = 0, in = 0, out = 0;
    scanf("%d", &n);

    while (i < n)
    {
        scanf("%d", &x);
        if (x <= 20 && x >= 10)
        {
            in++;
        }
        else if (x > 20 || x < 10)
        {
            out++;
        }
        i++;
    }
    printf("%d in\n", in);
    printf("%d out\n", out);

    return 0;
}
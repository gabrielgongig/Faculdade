#include <stdio.h>

int main()
{
    int x = 1, y = 1;

    while (x != 0 && y != 0)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        if (x != 0 || y != 0)
        {
            if (x > 0 && y > 0)
            {
                printf("primeiro\n");
            }
            else if (x > 0 && y < 0)
            {
                printf("quarto\n");
            }
            else if (x < 0 && y < 0)
            {
                printf("terceiro\n");
            }
            else if (x < 0 && y > 0)
            {
                printf("segundo\n");
            }
        }
    }
}
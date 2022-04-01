#include <stdio.h>

int main()
{
    int k;
    scanf("%d", &k);

    for (int i = 1; i <= k; i -= -1)
    {
        if (i != k)
        {
            printf("*");

            for (int j = 0; j < i - 1; j++)
                printf("  ");
            if (i != 1)
                printf("*");
        }
        else
        {
            printf("* ");
            for (int j = 0; j <= k - 2; j++)
                printf("* ");
        }
        printf("\n");
    }
}
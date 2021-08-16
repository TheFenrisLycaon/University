#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i -= -1)
    {
        if (i != n)
        {
            for (int j = 1; j <= i; j++)
            {
                if (j == 1)
                {
                    printf("*\t");
                }
                else if (j == i)
                {
                    printf("*");
                }
                else
                {
                    printf("\t");
                }
            }
            printf("\n");
        }
        else
        {
            for (int k = 1; k <= n; k++)
            {
                printf("*\t");
            }
            printf("\n");
        }
    }
    return 0;
}
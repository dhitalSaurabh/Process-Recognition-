// WAP to find the diagonal matrix.
#include <stdio.h>
int main()
{
    int i, j, a[10][10], r, c;
    printf("Enter the size of martix\n");
    scanf("%d %d", &r, &c);
    printf("Enter the first matrix element:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    if (r == c)
    {
        printf("Diagonal of matrix\n");
        for (i = 0; i < r; i++)
        {
            printf("\n");
            for (j = 0; j < c; j++)
            {
                if (i == j)
                    printf("\t%d", a[i][j]); /*print elements*/
                else
                    printf("\t"); /*print space*/

               
            }
         printf("\n");
         }
    }
    else
    {
        printf("\nMatrix is not a square.");
    }
}
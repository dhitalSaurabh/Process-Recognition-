// WAP to find th transpose of a matrix.
#include<stdio.h>
int main()
{
    int i, j, a[2][2], trans[2][2];
    printf("Enter the value of first matrix:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    // printf("Enter the value of second matrix:\n");
    // for(i=0;i<2;i++)
    // {
    //     for(j=0;j<2;j++)
    //     {
    //         scanf("%d", &b[i][j]);
    //     }
    // }

     for(i=0;i<2;i++)
    {
        
        for(j=0;j<2;j++)
        {
        trans[j][i] = a[i][j];
        }
    }
    printf("transpose of %d\n", a[i][j]);
     for(i=0;i<2;i++)
    {printf("\n");
        for(j=0;j<2;j++)
        {
            printf("%d\t\t",trans[i][j]);
        }
    }
   
}
// WAP to add two 2*2 matrix.
#include<stdio.h>
int main()
{
    int i, j, a[2][2],b[2][2],sum[2][2];
    printf("Enter the value of first matrix:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the value of second matrix:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

     for(i=0;i<2;i++)
    {
        
        for(j=0;j<2;j++)
        {
            sum[i][j] = a[i][j]+b[i][j];
        }
    }
    printf("sum\n");
     for(i=0;i<2;i++)
    {printf("\n");
        for(j=0;j<2;j++)
        {
            printf("%d\t\t", sum[i][j]);
        }
    }
   
}
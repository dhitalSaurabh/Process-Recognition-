// WAP to multiply two 3*3 matrix.
#include<stdio.h>
int main()
{
    int i, j, a[3][3],b[3][3],mul[3][3];
    printf("Enter the value of first matrix:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the value of second matrix:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

     for(i=0;i<3;i++)
    {
        
        for(j=0;j<3;j++)
        {
            mul[i][j] = a[i][j]*b[i][j];
        }
    }
    printf("Multiplication\n");
     for(i=0;i<3;i++)
    {printf("\n");
        for(j=0;j<3;j++)
        {
            printf("%d\t\t", mul[i][j]);
        }
    }
   
}
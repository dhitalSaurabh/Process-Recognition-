// WAP to input marks of 5 subjects and find their average and sum.

#include <stdio.h>
int main()
{
    int n[5], i, sum;
    float avg = 0;
    for (i = 0; i < 5; i++)
    {
        printf("Enter marks of %d subject:", i + 1);
        scanf("%d", &n[i]);
    }
    for (i = 0; i < 5; i++)
    {
        sum += n[i];
    }
    avg = sum / 5.0;
    printf("\nSum of 5 subject is %d\n", sum);
    printf("Average of 5 subject is %f\n", avg);
}
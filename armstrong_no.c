// WAP to check wheather the number is armstrong or not.
#include <stdio.h>
int main()
{
    int n, temp, sum = 0, d;
    printf("Enter the number: ");
    scanf("%d", &n);
    for (temp = n; n != 0; n = n / 10)
    {
        d = n % 10;
        sum = sum + (d * d * d);
    }

    if (sum == temp)
        printf("%d is an Armstrong number.\n", temp);
    else
        printf("%d is not an Armstrong number.\n", temp);
}
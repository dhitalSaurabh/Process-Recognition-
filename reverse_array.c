// WAP to reverse the elements of array.

#include <stdio.h>

int main()
{
    int arr[10];

    int n, i;
    // Inputting the size of the array
    printf("Enter the size of the array between 1-10: ");
    scanf("%d", &n);

    // Inputting the array
    printf("Enter an array: ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Printing the reverse of the array
    printf("Reversed array: ");
    for ( i = n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
}
// WAP to find the nth largest element of an array.
#include <stdio.h>
int main()
{
    int arr[100], n, i;
    printf("Enter the number of elements (1 to 100): ");
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        printf("Enter number %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    // storing the largest number to arr[0]
    for (i = 1; i < n; i++)
    {
        if (arr[0] < arr[i])
        {
            arr[0] = arr[i];
        }
    }

    printf("Largest element = %d\n", arr[0]);
}
// WAP to take input from an user and find the smallest and largest number.

#include <stdio.h>
int main()
{
    int n[10];
    int size, i;
    int smallest, largest;
    printf("Enter the size of the array between 1-10:");
    scanf("%d", &size);
    printf("Enter the element in the array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &n[i]);
    }
    smallest = n[0];
    largest = n[0];
    for (i = 0; i < size; i++)
    {
        if (n[i] < smallest)
        {
            smallest = n[i];
        }
        if (n[i] > largest)
        {
            largest = n[i];
        }
    }
    printf("Smallest number is %d\n", smallest);
    printf("Largest number is %d\n", largest);
}
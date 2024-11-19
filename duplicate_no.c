// WAP to find the duplicate number in the array.
#include<stdio.h>


 int main()
 {
  int i,arr[20],j,size;

  printf("Enter size of array: ");
  scanf("%d",&size);
  printf("Enter any %d elements in array: ",size);
  for(i=0;i<size;i++)
  {
   scanf("%d",&arr[i]);
  }
  printf("Duplicate elements are: ");
  for(i=0; i<size; i++)
   {
    for(j=i+1;j<size;j++)
    {
    if(arr[i]==arr[j])
    {
    printf("%d\n",arr[i]);
    }
   }
   }
 }
// 7. WAP to find the sum pof series [1-X^2/2!+X^4/4!-...].
#include<stdio.h>
int main()
{
float x,sum,t,d;
int i,n;
printf("Input the value of x:");
scanf("%f", &x);
printf("input the number of terms:");
scanf("%d", &n);

sum=1; t=1;
for(i=1;i<n;i++)
{
    d=(2*i)*(2*i-1);
    t= -t*x*x/d;
    sum+=t;
}
printf("\n the sum= %f\nNumber of terms=%d\nValue of x=%f", sum,n,x );
}
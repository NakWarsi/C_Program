#include<stdio.h>
int fact(int);
int main()
{
int a,c;
printf("enter the number to get factorials");
scanf("%d",&a);
c=fact(a);
printf("%d",c);
}
int fact(int n){
if(n>1)
 return fact(n-1)*n;
else
 return 1;
}


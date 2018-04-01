#include<stdio.h>
int fact(int);
int main()
{
int a,c;
printf("enter the number to find factorials");
scanf("%d",&a);
c=fact(a);
printf("%d",c);
return 0;
}

int fact(int n){
int fact=1;
	for(int i=1;i<=n;i++)
	{
	fact=fact*i;
	}
return fact;
}

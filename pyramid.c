#include<stdio.h>
int main()
{
int n=5;
for(int i=1;i<=n;i++)
{
int k=0;
       for(int j=1;j<=n-i;j++)
	{
	printf(" ");
	}
	while(k!=(2*i-1))
	{
	printf("*");
	k++;
	}
printf("\n");
}
}

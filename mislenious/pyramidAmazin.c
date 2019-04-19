#include<stdio.h>
#include<stdlib.h>
int main()
{
int n=80,k=1;
for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n-i;j++)
		{printf(" ");
		}
	for(int l=1;l<=2*k-1;l++)
		{
		printf("%d",(abs(k-l)%10));
		}
//printf("%d xyz",k);
	k+=1;
printf("\n");
	}
return 0;}

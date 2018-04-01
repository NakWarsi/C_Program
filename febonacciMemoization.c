#include<stdio.h>
//#define max 100
#define nil -1
const int max=100;
int lookup[max];

void _initialize()
{
for(int i=0;i<max;i++)
lookup[i]=nil;
}


int fab(int n)
{

//for(int i=0;i<max;i++)
//lookup[i]=nil;

	if(lookup[n]==nil)
	{
		if(n<=1)
		lookup[n]=n;
		else
		lookup[n]=fab(n-1)+fab(n-2);
	}

//printf("%d  ",lookup[n]);
return lookup[n];
//printf("%d",lookup[n]);
}


int main()
{
int n=6;
//fab(n);
_initialize();
//int x=fab(n);
printf(".....fab.........:  %d \n", fab(n));

return 0;
}

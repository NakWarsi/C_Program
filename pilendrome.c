#include<stdio.h>
int main()
{
int n;
printf("enter number to check if it is pilendrom");
scanf("%d",&n);
int len=1;
while(n!=0)
{
len=len*10;
n=n/10;
}
len=len/10;
int flag=0;
while(n>0)
{
	if(n/10==n%10)
		{
                n=n%len;
		n=n/10;
		}
        else{
	flag=1;
	break;	}
}

if(flag==0)
printf("a Pilendrome");
else
printf("not a pilendrome ");
}

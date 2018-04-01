#include<stdio.h>
int main()
{
int n;
printf("enter a no to find nearest smaller prime no.");
scanf("%d",&n);
int flag=1;
while(flag==1)
{
n--;
int i;
for(i=n/2+1;i>=2;i--)
{
if(n%i==0)
break;
else if(i==2)
{
flag=0;
}
}
}
printf("%d is a nerest smaller prime no.",n);
return 0;
}

#include<stdio.h>
int pilendrome(int);
int main()
{
int i=999,j;
int flag=0;
while(flag==0){
	for(;i>=100;i--)
	{
	int count=0;
	int k=0;
		for(j=999-k;j>=10;j--)
		{
//printf("%d*%d \n",i,j);	
//printf("k = %d \n",k);
int x=pilendrome(i*j);
//printf("X= %d \n",x);
		if(x==10)
		{flag=1;
		break;
		}
		k++;
//printf("%d",k);
		count++;
		if(count==10)
		break;	
		}
//printf("%d \n",k);
	if(flag==1)
	break;
	}
}
printf("%d \n",i*j);
return 0;
}




int pilendrome(int num)
{
//printf("num=%d \n",num);
int rev=0;
int p=num;
while(num>0){
rev=rev*10+num%10;
num=num/10;
}
//printf(" rev= %d\n",rev);
if(p==rev)
return 10;
else
return 20;
}

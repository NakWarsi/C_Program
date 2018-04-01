#include<stdio.h>
int main()
{
int n;
//printf("enter n numbers in the array\n");
//scanf("%d",&n);
int arr[5];
int min;
printf("now enter n values\n");
for(int i=0;i<5;i++)
{
scanf("%d",&arr[i]);
}
for(int i=0;i<5-1;i++)
{
	//printf("its running`");
	min=i;
	for(int j=i+1;j<5;j++)
	{
	//printf("j is running");
	if(arr[i]>arr[j])
	min =j;
	}
if(min!=i)
{
int temp=arr[min];
arr[min]=arr[i];
arr[i]=temp;
}
}
for(int i=0;i<5;i++)
printf("%d  ",arr[i]);
return 0;
}

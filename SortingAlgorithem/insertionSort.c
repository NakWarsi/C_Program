#include<stdio.h>
int main()
{
int arr[10]={55,12,28,77,18,64,90,97,45,33};
int min;
for(int i=0;i<10;i++)
{
min=i+1;
int j=i;
	while((arr[min]<arr[j])&&(j>=0))
	{
	int temp=arr[j];
	arr[j]=arr[min];
	arr[min]=temp;
	min--;
	j--;
	}
	
}
for(int i=0;i<10;i++)
{
printf("%d  ",arr[i]);
}

return 0;}

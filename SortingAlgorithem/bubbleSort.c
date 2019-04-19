#include<stdio.h>
int main()
{
int arr[10]={13,12,10,18,35,42,10,9,55,90};

for(int i=0;i<10-1;i++)
{
//int x=i;
//int y=i+1;

	for(int j=0;j<10-1;j++)
		{
		if(arr[j]>arr[j+1])
			{
			int temp=arr[j+1];
			arr[j+1]=arr[j];
			arr[j]=temp;
			}
		}
}
for(int i=0;i<10;i++)
{
printf("%d  ",arr[i]);
}


return 0;}

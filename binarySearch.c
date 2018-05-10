#include<stdio.h>
int binarysearch(int arr[],int l,int r,int x);
int main()
{
int result,n;
int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
printf("enter the number to search\n");
scanf("%d",&n);
result=binarysearch(arr,0,15,n);
printf("the number is at %d location\n",result);
return 0;}


//recursive method
int binarysearch(int arr[],int l,int r, int x)
{
if(r>=l)
	{
	int mid=l+(r-l)/2;
	
	if(arr[mid]==x)
		return mid;
	else if(x>arr[mid])
	 return binarysearch(arr,mid+1,r,x);
	else
	 return	binarysearch(arr,l,mid-1,x);
	}
return 0;
}

//iterative method
/*
int binarysearch(int arr[],int l,int r,int x)
{
while(r>=l)
	{
	int mid=l+(r-l)/2;
	if(arr[mid]==x)
		return mid;
	else if(x>arr[mid])
		l=mid+1;
	else
		r=mid-1;
	}
return 0;
}
*/

BAKWAS SA CODE H

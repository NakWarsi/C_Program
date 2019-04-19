#include<stdio.h>

void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}


int partition(int arr[], int l,int r)
{
int pivot=arr[r];
int i=l-1;
for(int j=l;j<=r-1;j++)
	{
	if(arr[j]<=pivot)
		{
		i++;
		swap(&arr[i],&arr[j]);
		}
	}
swap(&arr[i+1],&arr[r]);
return (i+1);
}


/*
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
		i++; // increment index of smaller element
		swap(&arr[i], &arr[j]);
		}
		}
		swap(&arr[i + 1], &arr[high]);
		return (i + 1);
		}
*/


void quicksort(int arr[],int l,int r)
{
if(l<r)
	{
	int pi=partition(arr,l,r);

	quicksort(arr,l,pi-1);
	quicksort(arr,pi+1,r);
	}	
}


int main()
{
//int n=10;
int arr[10]={5,34,112,13,10,123,32,32,155,144};
quicksort(arr,0,9);
for(int i=0;i<10;i++)
printf("%d  ",arr[i]);

return 0;}

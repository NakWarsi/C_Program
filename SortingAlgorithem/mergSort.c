#include<stdio.h>
void merg(int arr[],int l, int mid,int r);
void mergsort(int arr[],int l,int r);

int main()
{
int arr[]={5,6,2,5,85,23,11,4,53,52};
mergsort(arr,0,9);
for(int i=0;i<9;i++)
printf("%d  ",arr[i]);
return 0;
}

void mergsort(int arr[],int l,int r)
{
	if(l<r)
	{
		int mid=l+(r-l)/2;
	mergsort(arr,l,mid);
	mergsort(arr,mid+1,r);
	
	merg(arr,l,mid,r);
	}
}

void merg(int arr[],int l,int mid, int r)
{
//declaring size of parted array
int n1=mid-l+1;
int n2=r-mid;
//declaring temp array
int temp1[n1],temp2[n2];

for(int i=0;i<n1;i++)
temp1[i]=arr[l+i];

for(int i=0;i<n2;i++)
temp2[i]=arr[mid +1 +i];

int x=0;
int y=0;
int k=l;
while(x<n1 && y<n2)
{
	if(temp1[x]<temp2[y])	
	{
	arr[k]=temp1[x];
	x++;
	}
	else
	{
	arr[k]=temp2[y];
	y++;
	}
k++;
}

while(x<n1)
{
arr[k]=temp1[x];
x++;
k++;
}

while(y<n2)
{
arr[k]=temp2[y];
y++;
k++;
}

}

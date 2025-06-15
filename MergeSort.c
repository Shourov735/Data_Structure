#include<stdio.h>
#define MAX 100
int arr[MAX];
int temp[MAX];
void mergeSort(int start,int end);
void merge(int start,int mid,int end);
int main()
{
	int n;
	printf("Enter how many numbers you want to sort: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergeSort(1,n);

	printf("After merge sort:\n");
	for(int i=1;i<=n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0; 
}
void mergeSort(int start,int end)
{
	if(start>=end) return;
	int mid = start+(end-start)/2;
	for(int i=1;i<=end;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	mergeSort(start,mid);
	for(int i=1;i<=end;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	mergeSort(mid+1,end);
	for(int i=1;i<=end;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	merge(start,mid,end);
	for(int i=1;i<=end;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void merge(int start,int mid,int end)
{
	int i=start,rightStart=mid+1;  // i=temp position
	int num=end-start+1;
	while(start<=mid && rightStart<=end)
	{
		if(arr[start]<=arr[rightStart]) // < does not maintain FIFO but <= does
		{
			temp[i++]=arr[start++];
		}
		else
		{
			temp[i++]=arr[rightStart++];
		}
	}
	while(start<=mid)
	{
		temp[i++]=arr[start++];
	}
	while(rightStart<=end)
	{
		temp[i++]=arr[rightStart++];
	}
	for(int j=0 ;j<=num;j++)
	{
		arr[end]=temp[end];
		end--;
	}
}
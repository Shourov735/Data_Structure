#include<stdio.h>

void quickSort(int *a,int start,int end);
int partition(int *a,int start,int end);
int main()
{
	int n;
	printf("Enter how many numbers you want to sort: ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	quickSort(arr,0,n);

	printf("After quick sort:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
void quickSort(int *a,int start,int end)
{
	if(start>=end) return;
	int mid=partition(a,start,end);
	/*for(int i=0;i<end;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");*/
	quickSort(a,start,mid);
	/*for(int i=0;i<end;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");*/
	quickSort(a,mid+1,end);
	/*for(int i=0;i<end;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");*/
}
int partition(int *a,int start,int end)
{
	int pivot=a[end-1];
	int i=start-1;
	for(int j=start;j<end-1;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			
			/*for(int i=0;i<end;i++)
			{
				printf("%d ",a[i]);
			}
			printf("\n");*/
		}
	}
	i++;
	int temp=a[i];
	a[i]=a[end-1];
	a[end-1]=temp;
	return i;
}
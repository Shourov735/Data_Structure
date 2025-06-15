#include<stdio.h>
#define MAX 100
int a[MAX];
void selectionSort(int n);

int main()
{
	int n;
	printf("Enter how many numbers you want to sort: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	selectionSort(n);
	printf("After selection sort:\n");

	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0; 
}
void selectionSort(int n)
{
	for(int i=0;i<n;i++)
	{
		int minindex=i;
		int min=a[i];
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<min) // <= does not maintain FIFO but < does
			{
				minindex=j;
				min=a[j];
			}
		}
		int temp=a[i];
		a[i]=a[minindex];
		a[minindex]=temp;
	}
}

#include<stdio.h>
#define MAX 100
int a[MAX];
void bubbleSort(int n);

int main()
{
	int n;
	printf("Enter how many numbers you want to sort: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	bubbleSort(n);
	printf("After bubble sort:\n");

	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0; 
}
void bubbleSort(int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j+1]<a[j])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

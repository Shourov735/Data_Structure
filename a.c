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
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

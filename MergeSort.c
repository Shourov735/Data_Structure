#include<stdio.h>
#define MAX 100
int arr[MAX];

void mergeSort(int start,int end);

int main()
{
	int n;
	printf("Enter how many numbers you want to sort: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergeSort(0,n);

	printf("After merge sort:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0; 
}
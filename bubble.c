#include<stdio.h>
int main()
{
	int num,i,arr[100],j,temp;
	printf("enter the size of array\n");
	scanf("%d",&num);
	printf("enter the elements of the array\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nelements of the array before sorting\n");
	for(i=0;i<num;i++)
	{
		printf("%d",arr[i]);
	}
	for(i=0;i<num - 1;i++)
	{
		for(j=i;j<num - 1;j++)
		{
			if(arr[j+1] < arr[j])
			{
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("\nelements of the array after sorting\n");
	for(i=0;i<num;i++)
	{
		printf("%d",arr[i]);
	}
}

	


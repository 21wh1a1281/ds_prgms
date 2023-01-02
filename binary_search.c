#include<stdio.h>
int main()
{
	int num,arr[100],i,key,count = 0;
	printf("enter the size of array");
	scanf("%d",&num);
	printf("enter the elements of array in sorted list");
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the key to search");
	scanf("%d",&key);
	int low = 0,high = num - 1;
	while(low<=high)
	{
		if(key < arr[num/2])
		{
			high = num/2 - 1;
		}
		else if(key > arr[num/2]) 
		{
			low = num/2 + 1;
		}
		else if(key == arr[num/2]) 
		{
			printf("position of the element in array : %d",num/2 + 1);
			count = 1;
			break;
		}	
	}
	if(count == 0)
	{
		printf("the element is not found in the list");
	}
}






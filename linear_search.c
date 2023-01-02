#include<stdio.h>
int main()
{
        int arr[100],i,num,key,count = 0;
        printf("enter the size of array\n");
        scanf("%d",&num);
        printf("enter the elements of array\n");
        for(i=0;i<num;i++)
        {
                scanf("%d",&arr[i]);
        }
        printf("enter the key to search\n");
        scanf("%d",&key);
        for(i=0;i<num;i++)
        {
                if(key == arr[i])
                {
                        printf("element is found in position : %d",i+1);
                        count = 1;
                }
        }
        if(count == 0)
        {
                printf("the element is not found in the array");
        }
}


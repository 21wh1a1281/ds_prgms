#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
void insert();
void delete();
void display();
int front = -1,rear = -1;
int queue[maxsize];
void main()
{
	int choice;
	while(choice != 4)
	{
		printf("\n 1.insert an element 2.delete an element 3.displayqueue 4.exit");
		printf("enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert();
				break;
			case 2: delete();
				break;
			case 3: display();
				break;
			case 4: exit(0);
				break;
			default:
				printf("\n enter valid choice");
		}
	}
}
void insert()
{
	int item;
	printf("enter element\n");
	scanf("%d",&item);
	if(rear == maxsize-1)
	{
		printf("OVER FLOW");
		return;
	}
	if(front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		rear = rear+1;
	}
	queue[rear] = item;
	printf("value inserted");
}
void delete()
{
	int item;
	if(front == -1||front > rear)
	{
		printf("\nUNDER FLOW");
		return;
	}
	else
	{
		item = queue[front];
		front = front+1;
		printf("value deleted");
	}
}
void display()
{
	int i;
	if(rear == -1)
	{
		printf("empty queue");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
}





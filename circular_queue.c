#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

struct node* create_node(int num)
{
    struct node* ptr = malloc(sizeof(struct node));
    ptr -> val = num;
    ptr -> next = NULL;
    return ptr;
}

void enqueue(int num)
{
    struct node *new_node;
    new_node = create_node(num);
    if(front == NULL && rear == NULL)
    {
        front = rear = new_node;
        new_node -> next = new_node;
    }
    rear -> next = new_node;
    rear = new_node;
    rear -> next = front;
    
}

void dequeue()
{
    struct node* temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("\nqueue is empty");
    }
    else if(front == rear)
    {
        temp = front;
        front = rear = NULL;
        free(temp);
    }
    else
    {
        front = front -> next;
        rear -> next = front;
        free(temp);
    }
}

void display()
{
    if(front == NULL && rear == NULL)
    {
        printf("\nqueue is empty");
    }
    else
    {
        struct node *temp;
        temp = front;
        while(temp != rear)
        {
            printf("%d ",temp -> val);
            temp = temp -> next;
        }
        printf("%d",rear -> val);
    }
}

int main()
{
    enqueue(5);
    
    
    dequeue();
    dequeue();
    
    display();
    
}
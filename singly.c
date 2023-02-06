//singly
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void count_nodes(struct node *head)
{
    int count = 0;
    if(head == NULL)
        printf("linked list is empty");
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr -> link;
    }
    printf("%d\n",count);
}

void print_data(struct node *head)
{
    if(head == NULL)
        printf("linked list is empty");
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d",ptr -> data);
        printf("\n");
        ptr = ptr -> link;
    }
    
}

void insert_at_end(struct node *head)
{
    int num;
    printf("enter the value to be inserted");
    scanf("%d",&num);
    struct node *ptr,*temp;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));
    
    temp -> data = num;
    temp -> link = NULL;
    while(ptr -> link != NULL)
    {
        ptr = ptr -> link;
    }
    ptr -> link = temp;
    
}

struct node* insert_at_beg(struct node* head)
{
    int num;
    printf("enter the number to be inserted");
    scanf("%d",&num);
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> data = num;
    ptr -> link = head;
    return ptr;
}


struct node* del_at_beg(struct node* head)
{
    struct node *temp = head;
    head = head -> link;
    free(temp);
    temp = NULL;
    return head;
}

void del_at_end(struct node* head)
{
    while(head -> link -> link != NULL)
    {
        head = head -> link;
    }
    free(head -> link);
    head -> link = NULL;
}

void del_at_pos(struct node* head)
{
    int pos,count = 1;
    struct node *current,*prev;
    current = (struct node*)malloc(sizeof(struct node));
    prev = (struct node*)malloc(sizeof(struct node));
    printf("enter the position to be deleted");
    scanf("%d",&pos);
    current = head;
    prev = head;
    if(pos == 1)
    {
        head = head -> link;
    }
    else
    {   
        while(head -> link != NULL)
        {
            if(count == pos)
            {
                prev -> link = current -> link;
                break;
            }
            count++;
            prev = current;
            current = current -> link;
        }
    }
    
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;
    
    struct node *current = malloc(sizeof(struct node));
    current -> data = 98;
    current -> link = NULL;
    head -> link = current;
    
   current = malloc(sizeof(struct node));
   current -> data = 3;
   current -> link = NULL;
   head -> link -> link = current; 
   
   count_nodes(head);
   insert_at_end(head);
   head = insert_at_beg(head);
   head = del_at_beg(head);
   del_at_end(head);
   del_at_pos(head);
   print_data(head);
}




//double
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* insert_at_beg(struct node* head)
{
    int num;
    printf("enter the num to be inserted at beginning");
    scanf("%d",&num);
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp -> data = num;
    temp -> next = NULL;
    temp -> prev = NULL;
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    return head;
    
}

void traverse(struct node* head)
{
    struct node *ptr;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n",ptr -> data);
        ptr = ptr -> next;
    }
}

struct node* insert_at_end(struct node* head)
{
    int num;
    struct node *ptr,*temp;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter the data to be inserted at end");
    scanf("%d",&num);
    temp -> data = num;
    temp -> prev = NULL;
    temp -> next = NULL;
    while(ptr->next != NULL)
    {
        ptr = ptr -> next;
    }
    ptr -> next = temp;
    temp -> prev = ptr;
    return head;
    
}

struct node* insert_at_pos(struct node* head)
{
    int num,pos,count=1;
    printf("enter the number to be inserted");
    scanf("%d",&num);
    printf("enter the position to be inserted");
    scanf("%d",&pos);
    struct node *current,*temp,*ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    ptr = (struct node*)malloc(sizeof(struct node));
    current = (struct node*)malloc(sizeof(struct node));
    temp -> data = num;
    temp -> prev = NULL;
    temp -> next = NULL;
    ptr = head;
    current = head;
    while(ptr != NULL)
    {
        if(count == pos)
        {
            ptr -> next = temp;
            temp -> prev = ptr;
            temp -> next = current;
            current -> prev = temp;
            break;
        }
        ptr = current;
        current = current -> next;
        count++;
    }
    return head;
}

struct node* create()
{
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));
    int num,value,i;
    printf("enter the number of nodes");
    scanf("%d",&num);
    printf("enter the value to be inserted at pos 1 :");
    scanf("%d",&value);
    head -> data = value;
    head -> next = NULL;
    head -> prev = NULL;
    for(i=2;i<=num;i++)
    {
        head = insert_at_end(head);
    }
    return head;
}

struct node* del_at_beg(struct node* head)
{
    head = head -> next;
    free(head -> prev);
    head -> prev = NULL;
    return head;
}

struct node* del_last(struct node* head)
{
    struct node*ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr = head;
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    ptr -> prev = NULL;
    free(ptr);
    return head;
}

struct node* del_at_pos(struct node* head)
{
    int pos,count = 1;
    struct node *ptr,*current;
    ptr = (struct node*)malloc(sizeof(struct node));
    current = (struct node*)malloc(sizeof(struct node));
    current = head;
    ptr = head;
    printf("enter the position to be deleted");
    scanf("%d",&pos);
    while(ptr != NULL)
    {
        if(count == pos)
        {
            ptr = ptr -> next;
            current -> next = ptr;
            ptr -> prev = current;
            break;
        }
        current = ptr;
        ptr = ptr->next;
        count++;
    }
    return head;
    
}
int main()
{
    struct node* head = NULL;
    head = create();
    head = insert_at_beg(head);
    head = insert_at_end(head);
    head = insert_at_pos(head);
    head = del_at_beg(head);
    head = del_last(head);
    head = del_at_pos(head);
    
    traverse(head);
    
}





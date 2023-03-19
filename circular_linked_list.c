//circular
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* add_to_empty(int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    return temp;
}
struct node* add_to_end(struct node* tail,int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = tail -> next;
    tail -> next = temp;
    tail = temp;
    return tail;
}
void traverse(struct node* tail)
{
    struct node *temp;
    temp = tail -> next;
    do
    {
        printf("%d\n",temp -> data);
        temp = temp -> next;
    }
    while(temp != tail -> next);
    
}
struct node* create_list()
{
    struct node* tail;
    tail = (struct node*)malloc(sizeof(struct node));
    int num,data,i;
    printf("enter number of nodes");
    scanf("%d",&num);
    printf("enter the element 1 to be inserted : ");
    scanf("%d",&data);
    tail = add_to_empty(data);
    for(i=2;i<=num;i++)
    {
        printf("enter the element to be inserted at position %d : ",i);
        scanf("%d",&data);
        tail = add_to_end(tail,data);
    }
    return tail;
}

struct node* insert_at_beg(struct node*tail)
{
    int num;
    printf("enter the element to be inserted at beg : ");
    scanf("%d",&num);
    struct node *temp,*ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = num;
    ptr = tail -> next;
    temp -> next = ptr;
    tail -> next = temp;
    return tail;
}

struct node* insert_at_pos(struct node*tail)
{
    int num,count = 1,pos;
    printf("enter the value to be inserted");
    scanf("%d",&num);
    printf("enter the position to be inserted");
    scanf("%d",&pos);
    struct node *temp,*ptr,*current;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = num;
    ptr = tail -> next;
    current = tail -> next;
    while(ptr != tail)
    {
        if(count == pos)
        {
            current -> next = temp;
            temp -> next = ptr;
            break;
        }
        current = ptr;
        ptr = ptr -> next;
        count++;
    }
    return tail;
}

struct node* delete_beg(struct node* tail)
{
    tail -> next = tail -> next -> next;
    return tail;
}

struct node* delete_end(struct node* tail)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp = tail -> next;
    while(temp -> next != tail)
    {
        temp = temp -> next;
    }
    temp -> next = tail -> next;
    tail = temp;
    return tail;
}

struct node* delete_pos(struct node* tail)
{
    int count = 1,pos;
    printf("enter the position to be deleted");
    scanf("%d",&pos);
    struct node *temp,*ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    temp = tail -> next;
    ptr = tail -> next;
    while(temp != tail)
    {
        if(pos == count)
        {
            temp -> next = ptr -> next;
        }
        temp = ptr;
        ptr = ptr -> next;
        count++;
    }
    return tail;
}
int main()
{
    struct node *tail;
    tail = create_list();
    tail = insert_at_beg(tail);
    tail = insert_at_pos(tail);
    tail = delete_beg(tail);
    tail = delete_end(tail);
    tail = delete_pos(tail);
    traverse(tail);
}



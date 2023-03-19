#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int x)
{
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = x;
    new_node -> left = NULL;
    new_node ->right = NULL;
    
    return new_node;
}

void preorder(struct node*root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d  ",root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(struct node*root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root -> left);
    printf("%d  ",root -> data);
    inorder(root -> right);
}

void postorder(struct node*root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ",root -> data);
}

int count_nodes(struct node*root)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = count_nodes(root -> left);
    int right = count_nodes(root -> right);
    
    return left+right+1;
}

int h_tree(struct node*root)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = count_nodes(root -> left);
    int right = count_nodes(root -> right);
    if(left > right)
    {
        return left;
    }
    return right;
}

int sum_nodes(struct node*root)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = sum_nodes(root -> left);
    int right = sum_nodes(root -> right);
    
    return left+right+root -> data;
}

int main()
{
    struct node*root = create(4);
    root -> left = create(5);
    root -> right = create(10);
    root -> left -> left = create(7);
    root -> left -> right = create(8);
    root -> right -> right = create(1);
    
    printf("pre order is:");
    preorder(root);
    printf("\n");
    printf("in order is:");
    inorder(root);
    printf("\n");
    printf("post order is:");
    postorder(root);
    printf("\n");
    int h = h_tree(root);
    printf("height = %d",h);
    printf("\n");
    int count = count_nodes(root);
    printf("count = %d",count);
    printf("\n");
    int sum = sum_nodes(root);
    printf("sum = %d",sum);
    printf("\n");
    return 0;
}


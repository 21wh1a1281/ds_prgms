bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

SinglyLinkedListNode *ptr1,*ptr2;
ptr1 = head1;
ptr2 = head2;
while(ptr1 != NULL && ptr2 != NULL)
{
    if(ptr1 -> data != ptr2 -> data)
    {
        return 0;
    }
    else 
    {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
}
if(ptr1 == NULL && ptr2 == NULL)
{
    return 1;
}
return 0;
}

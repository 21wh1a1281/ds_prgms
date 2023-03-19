struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode*ptr;
    ptr = head;
    while(ptr -> next != NULL)
    {
        if(ptr -> val == ptr -> next -> val)
        {
            ptr -> next = ptr -> next -> next;
        }
        else
        {
            ptr = ptr -> next;
        }
    }
    return head;

}
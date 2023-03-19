struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *ptr,*temp,*current;
    if(head == NULL)
    {
        return head;
    }
    if(head -> next == NULL)
    {
        return head;
    }
    if(head -> next -> next == NULL)
    {
        ptr = head;
        temp = head -> next;
        temp -> next = ptr;
        ptr -> next = NULL;
        head = temp;
        return head;
    }
    ptr = head;
    temp = head -> next;
    current = head -> next -> next;
    ptr -> next = NULL;
    while(current != NULL)
    {
        temp -> next = ptr;
        ptr = temp;
        temp = current;
        current = current -> next;
    }
    temp -> next = ptr;
    head = temp;
    return head;

}
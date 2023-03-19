bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *ptr,*temp,*current;
    ptr = head;
    temp = head -> next;
    while(temp != NULL)
    {
        while(ptr != temp)
        {
            if(ptr -> next == temp -> next)
            {
                return true;
            }
            else 
            {
                ptr = ptr -> next;
            }
        }
        ptr = head;
        temp = temp -> next;
    }
    return false;
}

bool isPalindrome(struct ListNode* head){
    int count = 0; 
    struct ListNode *ptr,*current,*mid,*temp;
    ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr -> next; 
    }
    if(count == 0||count == 1)
        return true;
    if(count == 2)
    {
        if(head -> val == head -> next -> val)
            return true;
        return false;
    }
    current = head;
    if(count % 2 == 0)
    {
        temp = head -> next;
        current -> next == NULL;
        for(int i=1;i<count/2;i++)
        {
            ptr = current;
            current = temp;
            temp = temp -> next;
            current -> next = ptr;
        }
        head = current;
        while(temp != NULL)
        {
            if(head -> val != temp -> val)
                return false;
            head = head -> next;
            temp = temp -> next;
        }
        return true;
    }
    if(count == 3)
    {
        if(head -> val == head -> next -> next -> val)
            return true;
        return false;
    }
    for(int i=1;i<count/2;i++)
    {
        temp = current;
        current = current -> next;
        mid = current -> next;
    }
    current -> next = mid -> next;
    return isPalindrome(head);

}
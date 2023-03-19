struct ListNode* swapNodes(struct ListNode* head, int k){
    int temp1,temp2,count = 0;
    struct ListNode* ptr = head;
    while(ptr != NULL)
    {
        count++;
        if(count == k)
        {
            temp1 = ptr -> val;
        }
        ptr = ptr -> next;
    }
    printf("%d",count);
    if(count == 1)
    {
        return head;
    }
    if(count == 2)
    {
        int temp = head -> val;
        head -> val = head -> next -> val;
        head -> next -> val = temp;

        return head;
    }
    ptr = head;
    int count1 = 0;
    while(ptr != NULL)
    {
        if(count1 == count - (k))
        {
            temp2 = ptr -> val;
        }
        count1++;
        ptr = ptr -> next;
    }
    ptr = head;
    count1 = 0;
    while(ptr != NULL)
    {
        if(count1 == k -1)
        {
            ptr -> val = temp2;
        }
        if(count1 == count - (k))
        {
            ptr -> val = temp1;
        }
        ptr = ptr -> next;
        count1++;
    }
    return head;
}
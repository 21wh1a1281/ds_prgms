struct ListNode* middleNode(struct ListNode* head){
    int count = 1,pos;
    struct ListNode* ptr;
    ptr = head;
    while(ptr != NULL)
    {
        ptr = ptr -> next;
        count++;
    }
    if(count % 2 == 0)
    {
        pos = count/2;
    }
    else
    {
        pos = count/2 +1;
    }
    count = 1;
    while(count != pos)
    {
        head = head -> next;
        count++;
    }
    return head;
}
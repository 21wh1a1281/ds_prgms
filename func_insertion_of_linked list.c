struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ptr1,*ptr2;
    ptr1 = headA;
    ptr2 = headB;
    while(ptr1 != NULL)
    {
        ptr2 = headB;
        while(ptr2 != NULL)
        {
            if(ptr1  == ptr2 && ptr1 -> next  == ptr2 -> next )
            {
                return ptr1;
            }
            else
            {
                ptr2 = ptr2 -> next;
            }

        }
        ptr1 = ptr1 -> next;
    }
    return NULL;
}
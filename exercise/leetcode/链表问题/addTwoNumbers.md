简单题， 但是需要注意细节

1. 考虑 进位
2. 考虑 两个链表长度可能不一样。


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL; // 先将指针置空
    ListNode* cur;
    int inc = 0;
    while(l1!=nullptr || l2!=nullptr) { // 注意空指针的判断

        int a = l1 == nullptr?0:l1->val;
        int b = l2 == nullptr?0:l2->val;

        int sum = a + b + inc;
        int rem = sum % 10;

        ListNode* p = new ListNode(rem);
        
        if(head == NULL) {
            head = p;
            cur = p;
        }
        else{
            cur->next = p;
            cur = p;
        }

        inc = sum / 10; 
        l1 = l1==nullptr?nullptr:l1->next;
        l2 = l2==nullptr?nullptr:l2->next;

    }

    if(inc > 0){
        ListNode* p = new ListNode(inc);
        cur -> next = p;
    } 

    return head;
}
分组分部分反转链表， k为每组节点的数目。 如果最后有分组不足k , 保留原样

同反转相邻节点类似， 只是每组节点数目变多。

日常设置一个虚拟头结点 H, 考虑以下情况

pre -> p -> xxx -> q -> t -> xxxx

p为分组的起始元素， q为分组第k个节点 

如果 p== NULL || q == NULL 则结束， 返回 H->head;

进行一轮置换操作。
    头插大法好。


这个时候， 从t开始的后面的部分也可以递归解。

ListNode* reverseKGroup(ListNode* head, int k) {

    if(head == NULL || k < 2) return head;

    ListNode* H = new ListNode(-1, head);
    ListNode* pre = H;
    ListNode* p = pre -> next;
    
    while(p!= NULL && p->next != NULL){
        ListNode* q = p -> next;
        int step = 2;
        while(q!=NULL && step < k){
            q = q -> next;
            step++;
        } 
        if(q==NULL) break;

        ListNode* t = q -> next;
        ListNode* subH = t;
        ListNode* a = pre -> next;
        while(a!=t){
            pre -> next = a -> next;
            a -> next = subH;
            subH = a;
            a = pre -> next;
        }
        pre -> next = subH;
        pre = p;
        p = t;
    }

    return H->next;
}
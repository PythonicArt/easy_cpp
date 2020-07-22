替换每相邻的两个节点， 返回最终的头结点。 只能换指针， 不能换节点内容。 

换节点内容轻松且愉快, 可惜。

设置一个虚拟头结点 H, 考虑以下情况

pre -> p -> q -> t -> xxxx

如果 p== NULL || q == NULL 则结束， 返回 H->head;

进行一轮置换操作。

t = q->next;
p -> next = t;
pre -> next = q;
q -> next = p;
pre = p;

ListNode* swapPairs(ListNode* head) {

    ListNode* H = new ListNode(-1, head);

    ListNode* pre = H;
    ListNode* p = pre -> next;
    whiel(p!= NULL && p -> next != NULL){
        ListNode* q = p -> next;
        ListNode* t = q -> next;
        p -> next = t;
        pre -> next = q;
        q -> next = p;
        pre = p;
        p = t;
    }

    return H->next;
}

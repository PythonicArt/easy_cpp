移除倒数第n个节点， 要求， 只遍历一遍。(挠破狗头也没想出来)

设立两个指针， p, q, 先让q多走n步。 然后p， q同步往后走， 知道q走到结尾。
p指向的就是第n-1个节点, 执行删除操作即可。

特殊情况， 可能删除头结点。用一个虚拟的头结点， 统一所有操作。

题目假设head n均有效， 不做边界检查。

ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* H = new ListNode(-1, head);

    ListNode *p = H;
    ListNode *q = H;

    // q先走n步
    while(n>0){
        q = q->next;
        n--;
    }

    // 同步走
    while(q->next != NULL){
        p = p-> next;
        q = q -> next;
    }

    // 删除操作
    q = p -> next;
    p -> next = q -> next;
    delete q;
    return H -> next;
}
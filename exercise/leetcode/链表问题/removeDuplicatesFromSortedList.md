

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* p = head;
    while(p!=NULL&&p->next!=NULL){
        ListNode* q = p->next;// error0: 注意需要确定p不为NULL
        if(p->val == q->val){
            p->next = q->next;
            delete q;
        }else{ // error1: 这里只有在p, q两个元素不同时， p才能后移
            p = p->next;
        }
    }
    return head;   
}


拓展， 只保留没有重复地元素。

两种情况的合并
    1. 头部元素重复
    2. 头部元素不重复。
    新建一个虚拟的头， 两个问题统一处理。

pre -> p -> q -> xxxx

如果p,q节点值相同， 则 p=p->next, 

直到 节点值不同。
    此时有两种情况
    1. p需要删除
    2. p不需要删除

注意循环跳出后， 还需要判断一下p是否需要删除
 
ListNode* deleteDuplicates(ListNode* head) {
    bool repeat = false;
    ListNode* H = new ListNode(-1, head);
    ListNode* pre = H;
    ListNode* p= pre -> next;

    while(p!=NULL&&p->next!=NULL){
        ListNode* q = p->next;
        if(p->val == q->val){
            repeat = true;
            p->next = q->next;
            delete q;
        }else{
            if(repeat){
                pre -> next = q;
                delete p;
                p = q;
                repeat = false;
            }else{
                pre = p;
                p=q;
            }
        }
    }

    if(repeat){
        pre -> next = NULL;
        delete p;
    }

    return H -> next;
}

递归的解法

任何时候考虑 链表为以下状态


如果head节点的值不唯一， 连续删除头结点， 直到元素唯一。 
head -> (left)

子问题：
递归求 left， 将结果作为 head -> next

递归的跳出：
 head == NULL || head -> next == NULL

ListNode* deleteDuplicates(ListNode* head) {

    if(head == NULL || head -> next == NULL) return head;

    ListNode* p = head -> next;
    if(p -> val == head -> val){
        while(p!= NULL && p->val == head ->val){
            head -> next = p -> next;
            delete p;
            p = head -> next;
        }
        delete head;
        return deleteDuplicates(p);
    }
    else{
        head -> next = deleteDuplicates(head -> next);
        return head;
    }
    

}
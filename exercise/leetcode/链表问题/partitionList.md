将节点分成三组
A 小于x的组， shead, stail
B 大于或等于x的组 bhead, btail
C 待检查的组 cur

从左到右遍历检查， 找到属于某个组的元素就往里加， 最后返回 shead bhead 某个不为空的值。

ListNode* partition(ListNode* head, int x) {
    ListNode *cur = head;
    ListNode *shead = NULL, *stail = NULL, *bhead = NULL, *btail = NULL;

    while(cur!=NULL){ // warning: 题目给的条件是NULL, 不再是 nullptr, 倒也不影响结果
        if((cur -> val) < x){
            if(shead == NULL){
                shead = cur;
                stail = cur;
            }else{ // error1: 这里的else漏掉了, 无情
                stail -> next = cur;
                stail = cur;
            }
            cur = cur -> next;
            stail -> next = NULL; 
        }
        else{
            if(bhead == NULL){
                bhead = cur;
                btail = cur;
            }else{
                btail -> next = cur;
                btail = cur;
            }
            cur = cur -> next;
            btail -> next = NULL; // error4: 这里无论如何都要把尾节点的next指针置空，不然会产生死循环。 
        }
    }

    if(stail != NULL) stail -> next = bhead; // error3: 这里最开始写的是 stail = bhead; emmmmm

    return shead!=NULL?shead:bhead;

}
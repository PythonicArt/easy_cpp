往右旋转链表， k次。 

先遍历得到链表的长度 len, 根据k ， 计算以下节点指针


h2->xx-> xx - > e2 -> h1 -> xxxx -> e1

将 e2断开， e1->next = h2, 返回 h1即可。

特殊情况 k % len ==0, 返回h2


ListNode* rotateRight(ListNode* head, int k) {

    if(k== 0 || head == NULL || head -> next == NULL)  return head;

    int len = 1; // error1: 第一次赋值为0

    ListNode* end = head;
    while(end -> next != NULL){
        len++;
        end = end -> next;
    }

    int left = k % len;
    if(left == 0) return head;

    ListNode* p = head;
    for (int i = 1; i < len - left; ++i)
    {
        p = p-> next;
    }
    ListNode* q = p -> next;

    p -> next = NULL;
    end -> next = head;
    return q;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



L0→L1→…→Ln-1→Ln,
变成 
L0→Ln→L1→Ln-1→L2→Ln-2→…

取中间的一个或两个元素, 将链表分成两部分

(0:mid-1) L(mid) | (mid+1, n)

把后面一部分 逆序 (n:mid+1), 在逐一插入到第一部分

如何获得中间的节点
    快慢指针， slow一次走一步， fast一次走两步。 当fast越过结尾， 则slow->next及以后为需要反转的部分


class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return;

        ListNode *slow = head, *fast = head;

        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        if(slow -> next == nullptr) return;


        ListNode *pre = slow->next;
        ListNode *cur = pre -> next;
        while(cur!=nullptr){
            pre->next = cur->next;
            cur -> next = slow -> next;
            slow->next = cur;
            cur = pre->next;
        }

        ListNode *p = head, *q = slow -> next;
        while(q!=nullptr){
            slow -> next = q -> next;
            q -> next = p -> next;
            p-> next = q;
            p=q->next;
            q=slow->next;
        }

        return;

    }
};
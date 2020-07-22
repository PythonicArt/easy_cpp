/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

判断是否有环
四年前遇到的问题， 终于又出现了。

缓存法， 用一个map记录出现的节点的索引。 用指针 一直往下走， 遇到已经出现的指针就认为有环。 如果到结尾则认为没有环

快慢指针 fast, slow. fast每次走两步， slow每次走一步。 
如果有环， fast 和 slow最后终将相遇

如果fast遇到NULL, 则说明没有环

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;

        ListNode *fast=head, *slow=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) return true;
        }

        return false;
    }
};


升级一下， 找到环的入口节点

常规解法， 缓存已经出现的节点， 遇到第一个已经出现的节点就是环的入口节点。

空间复杂度为常量的解法， 也是经过数学计算的公式法。

    同样设置快慢指针。当fast与slow相遇， 假设走了slow走了s步，fast走了2s步, 相遇时刻 fast比slow多走n圈
    假设环长 r， 
        2s = s+ nr
        s = nr 

    设环的入口点和相遇点距离为a， 起点到环入口点距离为x,  则说明没有环

        s = x + a = nr = (n-1)*r + L-x

        x = (n-1)*r + (L-x-a)

        网上一些解答对公式没有详细的解释， 而是直接推出  x = L-x-a 这是有缺严谨的。在这里给出一个解释，

        这个公式说明了 起点到环入口点距离为x 为 相遇点到入口的距离(L-x-a) 加上 （n-1）圈
        换一个角度想， 如果两个指针 A, B， A从起始点出发， B从相遇点出发， 走x步之后,  A到达入口处。
        B先走到入口处， 再走 (n-1)圈， 也回到入口处。 也就是两个指针必然会在入口处相遇。

仍然需要判断是否有环。

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL) return NULL;

        ListNode *fast=head, *slow=head;
        bool hasCycle = false;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle) return NULL;

        fast = head;
        while(fast!=slow){
            fast = fast -> next;
            slow = slow -> next;
        }

        return slow;
    }
};


还有一种更骚的解法， 假设链表的节点地址是递增的。 那么就设置 pre, cur, 
只要在退出前， cur < prev, 也就是回到了已经出现的节点，该节点就是环的入口
这个版本竟然可以ac

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur && cur > prev){
            prev = cur;
            cur = cur->next;
        }
        return cur;
    }
};


网上资料的的一些衍生探讨

1. 判断是否有环， 有的话求环的长度
2. 如果有环， 把环断开
3. 判断两个链表是否相交， 如果相交 找到 第一个相交的节点

    判断两个链表是否相交
        先判断各自是否有环
            只有一方有环， 则必定不相交
            如果都没有环， 判断尾节点是否相同
            如果都有环， 判断其中一个环上的节点， 是否在另一个链表上。

    找到第一个相交点
        求出两个链表的长度L1,L2（如果有环，则将Y点当做尾节点来算），假设L1<L2，用两个指针分别从两个链表的头部开始走，长度为L2的链表先走(L2-L1)步，然后两个一起走，直到二者相遇。

        






























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


迭代版本, 头插法

ListNode* reverseList(ListNode* head) {
    ListNode* rHead = new ListNode(0);
    ListNode *p, *q; // error1: 注意指针变量的连续声明， 不要写成 ListNode* p, q; 此时q是ListNode类型， 而不是指针类型

    while(head!=nullptr){
        p = head -> next;
        q = rHead -> next;
        rHead->next = head;
        head->next = q;
        head = p;
    }

    return rHead -> next;
}

递归版本。 
f(n)
    每次从链表中头部取出一个节点, 这个节点将是 f(n-1)的下一个节点

    当遇到尾节点则返回

    由于这里递归是用 尾部节点计算的， 结果需要返回头部节点，可以额外记录一个头部节点

ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head -> next == nullptr) return head;
    pair<ListNode*, ListNode*> r = reverseListCur(head);
    return r.first; // error1: pair的使用问题，这里r是对象，不是指针， 不能用r->first
}

pair<ListNode*, ListNode*> reverseListCur(ListNode* head) {
    if(head -> next == nullptr) return make_pair(head, head);

    ListNode* p = head;
    head = head -> next;
    p->next = nullptr; // error2: 省略了这一步， 没有和之前的链表断开

    pair<ListNode*, ListNode*> r = reverseListCur(head);

    r.second -> next = p;

    return make_pair(r.first, p); // error3: 这里传入了 make_pair(r.first, r.second) 想当然了
}


官方给出的 递归版本。



递归返回头结点，子句执行的是 f(head.next), 也就是 head在本次递归是保留的，

以 head, n1, n2,xxxx, tail 为例

head (tail, xxxx, n2, n1)

此时 head-> next 仍然是指向n1的, 而此时n1已经是链表的尾节点了， 将head成为新的尾节点， 返回头结点即可

public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}


范围内反转， 可以将原链表分成三段， ooooo A B C ... ppppp

记 第一段尾节点为 t1
第二段头结点为 h2

需要反转的一段的 头尾节点 分别为 shead, stail

反转时新建一个临时头结点 tmpHead

最后合并结果
    t1->next = tmpHead -> next;
    不要改变 shead的指向， 反转后， shead就成为了尾节点
    stail -> next = h2;

返回head

一些特殊情况的判断
    m==n 直接返回
    t1为空， 此时返回就是 tmpHead -> next



ListNode* reverseBetween(ListNode* head, int m, int n) {

    if( m == n || head == nullptr || head -> next == nullptr ) return head;

    // 确定位置
    ListNode *p, *t1=NULL, *shead, *h2; // error1:t1先赋空值，后面用作判断
    p=head;
    for (int i = 1; i <=n ; ++i)
    {
        if(i == m-1){
            t1 = p;
        }
        if( i == m){
             shead = p;
        }
        if(i == n){
            h2 = p->next;
        }
        p = p->next;
    }

    // 开始反转
    ListNode* rHead = new ListNode(0);
    ListNode *a, *b;
    ListNode *chead = shead;

    while(chead!=h2){
        a = chead -> next;
        b = rHead -> next;
        rHead->next = chead;
        chead->next = b;
        chead = a;
    }

    // 拼接链表
    shead -> next = h2;

    if(t1 != NULL){
        t1 -> next = rHead -> next; 
        return head;
    }
    return rHead->next; // error2: 逻辑错误, 不能返回 shead
    
}


一个优化的版本。

使用一个临时头结点tmpNode， 在t1为起始位置，进行节点头插。 如果t1不存在， 那么就是tmpNode

ListNode* reverseBetween(ListNode* head, int m, int n) {

    if( m == n || head == nullptr || head -> next == nullptr ) return head;

    ListNode *tmpHead = new ListNode(-1);
    tmpHead -> next = head;

    ListNode *prev = tmpHead;
    for (int i = 0; i < m - 1; ++i)
    {
        prev = prev -> next;
    }

    ListNode *stail = prev -> next;
    ListNode *p = stail;
    for (int i = m; i <= n; ++i)
    {
        ListNode *q = p -> next;
        p ->next = prev -> next;
        prev -> next = p;
        p = q;
    }

    stail -> next = p;
    return tmpHead ->next;

}
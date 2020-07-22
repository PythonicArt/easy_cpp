/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


复制链表，每个节点多一个随机指针。 

关键点在于 随机指针指向的可能是一个 当前还没有出现的节点。

使用map

令复制的链表头结点为 H

先 执行一遍复制， 只复制next, 
    每遇到一个节点p, 新增一个节点q,  新加 map[p] = q.

再执行一遍复制random 
    p, q分别执行两个链表的头结点， 同步往下走
     获得 rp = p->random, 从map里查到对应的 新加节点 rq, q->random = rq 


Node* copyRandomList(Node* head) {

    if(head == NULL) return head;

    Node* H = new Node(head -> val);

    Node* p = head;
    Node* q = H;
    map<Node*, Node*> M;

    while(p!=NULL){
        M[p] = q;
        if(p->next!=NULL){
            q -> next = new Node(p->next->val);                  
        }
        p=p->next;
        q=q->next;
    }

    p = head;
    q = H;

    while(p!=NULL){
        if(p->random!=NULL){
            q->random = M[p->random];              
        }
        p=p->next;
        q=q->next;
    }

    return H;
    
}

看到的一种让空间复杂度为常量的 解法

第一步增加节点， 在每一个节点后面增加一个和自己值相同的节点。

也就形成 
A->A1 -> B -> B1 -> ... -> Z -> Z1

第二步复制 random 
    p -> next-> random = p ->　random -> next
    p = p->next->next

第三步 两个链表拆分开来, 新建一个虚拟头结点 H
    p = head;
    q = H;
    while(p!=NULL){
        q -> next = p->next;
        p -> next = p -> next -> next;
        q = q-> next;
        q-> next = NULL;
        p = p-> next;
    }


Node* copyRandomList(Node* head) {
    if(head == NULL) return head;

    Node* p = head;
    Node* q;

    // 复制节点
    while(p!=NULL){
        q = new Node(p->val);
        q->next = p->next;
        p->next = q;
        p = q->next;
    }

    //复制random
    p = head;
    while(p!=NULL) {
        q = p->next;
        if(p->random !=NULL){
            q->random = p->random->next;
        }
        p = q->next;
    }

    //拆分链表
    p = head;
    Node* H = new Node(-1);
    q = H;
    while(p!=NULL){
        q -> next = p->next;
        p -> next = p -> next -> next;
        q = q-> next;
        q-> next = NULL;
        p = p->next;
    }

    return H->next;

}
    



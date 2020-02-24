删除倒数第k个

前提是不知道总的数量n
双链表也不知道尾节点(如果知道的话, 直接往前找了)

删除链表中的一个节点， 需要知道要删除节点的前置节点

删除倒数第k个, 就是删除第 n-k+1个，需要找到第n-k个

方法一
先遍历一遍得到长度n, 在从头找到第 n-k个节点， 然后操作

方法二
找一个中间计数count = k, 从头开始遍历， 没遇到一个节点计数 -1
当遍历完毕之后， 会出现以下情况
1. 计数值>0, 链表长度n < k, 按越界处理
2. 计数值=0, 列表长度刚好为k， 也就是 删除头操作
3. 计数值 count < 0, 链表长度 n = k-count,  我们要找到 n-k个节点 也就是 k-count-k = -count, 直接再遍历一遍就可找到

边界检查
头结点为空 或 k<1

```cpp

Node* removeLastKthNode(Node *head, int lastKth)
{
    if(head == NULL || lastKth < 1)
    {
        return head;
    }
    Node* cur = head;
    while(cur != NULL)
    {
        lastKth--;
        cur = cur->next;
    }
    if(lastKth == 0)
    {
        head = head->next;
    }
    if(lastKth < 0)
    {
        cur = head;
        while(++lastKth != 0)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
    return head;
}

```

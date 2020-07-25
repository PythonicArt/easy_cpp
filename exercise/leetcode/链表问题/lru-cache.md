class LRUCache {
private:
    struct cacheNode{
        int key;
        int value;
        cacheNode(int k, int v):key(k), value(v){}
    };
    list<cacheNode> L;
    unordered_map<int, list<cacheNode>::iterator> M;
    int capacity;
    int count;

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        this -> count = 0;
    }
    
    int get(int key) {
        if(M.find(key)!=M.end()){
            auto it = M[key];
            int value = it->value;
            L.erase(it);
            L.push_front(cacheNode(key, value));
            M[key]=L.begin();
            return value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        bool add = false;
        if(M.find(key)!=M.end()){
            L.erase(M[key]);
            L.push_front(cacheNode(key, value));
            M[key]=L.begin();
        }else{
            if(count >= capacity){
                cacheNode tmp = L.back();
                L.pop_back();
                M.erase(tmp.key);
                count--;
            }
            L.push_front(cacheNode(key, value));
            M[key]=L.begin();
            count++;            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


题目要求操作时o(1) 复杂度， 能够想到的就是map
同时， 需要一个额外的结够来维护 节点的排序。

考虑一个链表， 头结点head为最近使用的节点， 尾节点tail为最久使用的节点。
使用 std:list， 这是一个双向链表, 头尾节点可以直接拿到， 不用自己实现。

每个链表的元素 
    CacheNode{
        int key;
        int value;
    }

map 存储的结构 key, iterator of List

count 记录当前节点的数量

当插入一个新节点(key, value)
    查询map, 如果存在， 则更新
        通过 迭代器获得值，将迭代器对应的节点从链表中删除，新增一个 (key, value) 的节点到头部， 更新map。

    如果不存在
        判断是否超过容量， 如果是的， 先删除尾节点， 清除map对应的元素， count--

        在头部新增一个(key, value)节点， count++， 更新map


当查询一个节点
    先查询map, 如果不存在则返回-1， 存在则通过 迭代器获得值，将迭代器对应的节点从链表中删除，新增一个 (key, value) 的节点到头部, 更新map。


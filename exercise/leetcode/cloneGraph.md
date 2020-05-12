克隆一个图, Node节点的表示如下, 需要deep_copy, 生成新的图的节点， 新的图的节点的值和各节点的连接关系和原图一致

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
}
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
    }
};

```

## 第一次提交-超时
1. 使用了两个辅助结构, 而且第二个map存的是节点, 而不是索引
```cpp
map<int, bool> signs;
map<int, Node> nodes;
Node* cloneGraph(Node* node) {
    int value = node -> val;
    signs[value] = true;
    Node* start = getCopy(value);
    for (size_t i = 0; i < node -> neighbors.size(); i++) {
        Node* tmp = (node -> neighbors)[i];
        start -> neighbors.push_back(getCopy(tmp -> val));
        if(signs.find(tmp -> val) == signs.end()){
            cloneGraph(tmp);
        }
    }
    return start;
}
Node* getCopy(int value){
    if(nodes.find(value) == nodes.end()){
        Node newN(value);
        nodes[value] = newN;
        return &(nodes[value]);
    }
    else{
        return &((nodes.find(value)) -> second);
    }
}

```

## 第二次提交-没有边界检查
1. 将第二个map改成索引的方式, 不会超时
```cpp
map<int, bool> signs;
map<int, Node*> nodes;
Node* cloneGraph(Node* node) {
    if(node == NULL) return node;
    int value = node -> val;
    signs[value] = true;
    Node* start = getCopy(value);
    for (size_t i = 0; i < node -> neighbors.size(); i++) {
        Node* tmp = (node -> neighbors)[i];
        start -> neighbors.push_back(getCopy(tmp -> val));
        if(signs.find(tmp -> val) == signs.end()){
            cloneGraph(tmp);
        }
    }
    return start;
}
Node* getCopy(int value){
    if(nodes.find(value) == nodes.end()){
        Node* nNode = new Node(value);
        nodes[value] = nNode;
        return nNode;
    }
    else{
        return nodes[value];
    }
}

```

## 第三次提交-改成一个辅助结构
```cpp
map<int, Node*> nodes;
Node* cloneGraph(Node* node) {
    int value = node -> val;
    Node* start = getCopy(value);
    for (size_t i = 0; i < node -> neighbors.size(); i++) {
        Node* tmp = (node -> neighbors)[i];
        if(nodes.find(tmp -> val) == nodes.end()){
            cloneGraph(tmp);
        }
        start -> neighbors.push_back(nodes[tmp -> val]);
    }
    return start;
}
Node* getCopy(int value){
    if(nodes.find(value) == nodes.end()){
        nodes[value] = new Node(value);
    }
    return nodes[value];
}
```

参考代码-
1. 使用 unordered_map 竟然可以将时间 从 12ms 提升到 8ms
参考 两者区别 https://blog.csdn.net/batuwuhanpei/article/details/50727227
2. 使用原节点的指针作为索引 可以使代码更简洁
```cpp

unordered_map<Node*,Node*> m;
Node* cloneGraph(Node* node) {
    if(!node) return NULL;
    Node* root = new Node(node->val);
    m[node] = root;
    for(auto n : node->neighbors) {
        if(m.find(n) ==m.end()) {
            Node* nei = cloneGraph(n);
            root->neighbors.push_back(nei);
        } else {
            root->neighbors.push_back(m[n]);
        }
    }
    return root;
}

```

问题
0. 方案还没确定就写代码, 凭感觉写代码
0. 没有考虑边界检查
    输入数据的范围， 可能出现的情况
1. 编码效率是很低下的， 目测的检查水平很低， 有些if条件语句的判断都是反的。 只有跑用例的时候才能检查出来。
    <!-- * 检查语法 -- linter -->
    * 检查方案是否可行
    * 检查循环, 条件语句
    * 边界数据检查
    * 测试用例检查
3. 没有考虑如何优化代码. 一些优化的方向
    * 时间效率-更快的计算方法
    * 更少的辅助结构
    * 更高效的辅助结构
    * 更优美, 简洁的代码

当前编码习惯非常不好, 需要梳理过程
1. 提出可行方案(计算方法, 辅助结构等) 伪代码
2. 编码
3. 检查
    * 检查方案是否完全完成
    * 检查循环, 条件语句
    * 边界数据检查
    * 测试用例检查
4. 优化

一些误区
1. 代码是一蹴而就的。 不， 代码是一点点优化的。 从大致的结构到具体的边界检查。 一步步细化
2. 编码和测试是分开的。 不， 测试应该指导编码。

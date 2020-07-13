#include <cstdlib>
#include <iostream>
#include <stack>
#include <map>
#include <numeric>

#include "common.h"

using namespace std;

template <typename T>
void compare(int id, T result, T expect){
    if (result == expect) {
        printf("case %d passed\n\n", id);
    }
    else{
        printf("xxxxxxx-case %d unpassed\n", id);
        cout<< "result is " << result <<endl;
        cout<< "expect is " << expect << "\n" <<endl;
        cout<<endl;
    }
}

// 优先安排测试数据

int longestConsecutive(vector<int>& nums) {
    map<int, int> Signed;
    int longest = 0;
    for(int i:nums){
        if(Signed.find(i) != Signed.end()) continue;
        int RightAtMost = i;
        int LeftAtMost = i;
        int big = i+1;
        int small = i-1;
        Signed[i] = 1;
        if(Signed.find(big) != Signed.end() && Signed.find(small) != Signed.end()){
            Signed[i] += Signed[big] + Signed[small];
            RightAtMost = i + Signed[big];
            Signed[RightAtMost] = Signed[i];
            LeftAtMost = i - Signed[small];
            Signed[LeftAtMost] = Signed[i];
        }
        else if(Signed.find(big) != Signed.end()){
            Signed[i] += Signed[big];
            RightAtMost = i + Signed[big];
            Signed[RightAtMost] = Signed[i];
        }
        else if(Signed.find(small) != Signed.end()){
            Signed[i] += Signed[small];
            LeftAtMost = i - Signed[small];
            Signed[LeftAtMost] = Signed[i];
        }
        if(Signed[i] > longest) longest = Signed[i];
    }
    return longest;
}

template <typename T>
void Solution<T>::checkCase(){
    // int size1 = this -> numInput.size();
    // int size2 = this -> numOutPut.size();
    vector<int> a1 = {100, 4, 200, 1, 3, 2};
    vector<int> b1 = {5};

    vector<int> a2 = {1, 2, 3, 4};
    vector<int> b2 = {5, 6};

    vector<int> a3 = {1, 3};
    vector<int> b3 = {2};

    vector<int> a4 = {1, 2};
    vector<int> b4 = {3, 4};

    vector<vector<int> > a = {a1, a2, a3, a4};
    vector<vector<int> > b = {b1, b2, b3, b4};

    vector<int> expects = {4, 4, 1, 2};

    int size1 = a.size();
    int size2 = b.size();
    if ( size1 != size2) {
        printf("case case size unmatch!!! size %d size %d \n", size1, size2);
    }
    else{
        for (int i = 0; i < size1; i++) {
            int result = longestConsecutive(a[i]);
            int expect = expects[i];
            compare(i+1, result, expect);
        }
    }
}

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


class Solution1 {
public:

    map<int, bool> pSigns;

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

    void subPrintGraph(Node* node){
        cout << node->val << " ";
        pSigns[node -> val] = true;
    }

    void printGraph(Node* node){
        subPrintGraph(node);
        for (size_t i = 0; i < node -> neighbors.size(); i++) {
            Node* tmp = (node -> neighbors)[i];
            // cout << tmp -> val << endl;
            if(pSigns.find(tmp -> val) == pSigns.end()){
                printGraph(tmp);
            }
        }
    }

};

// void test(){
//
//     Node a;
//     a.val = 1;
//
//     Node b;
//     b.val = 2;
//
//     Node c;
//     c.val = 3;
//
//     Node d;
//     d.val = 4;
//
//     vector<Node * > v1 = {&b, &d};
//     a.neighbors = v1;
//     vector<Node * > v2 = {&a, &c};
//     b.neighbors = v2;
//     vector<Node * > v3 = {&b, &d};
//     c.neighbors = v3;
//     vector<Node * > v4 = {&a, &c};
//     d.neighbors = v4;
//
//     Solution1 s;
//     Node* m = s.cloneGraph(&a);
//     s.printGraph(m);
//
// }

int minCandy(vector<int> &ratings, vector<int> &t, int i){
    int n = ratings.size();
    if(t[i] == 0){
        t[i] = 1;
        if(i > 0){
            if (ratings[i] > ratings[i - 1]) {
                t[i] = max(t[i], minCandy(ratings, t, i-1) + 1);
            }
            else {
                t[i] = max(t[i], 1);
            }

        }
        if(i < n - 1){
            if (ratings[i] > ratings[i + 1]) {
                t[i] = max(t[i], minCandy(ratings, t, i+1) + 1);
            }
            else {
                t[i] = max(t[i], 1);
            }
        }
    }
    return t[i];
}

int candy(vector<int>& ratings) {
    int n = ratings.size();
    std::vector<int> t(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += minCandy(ratings, t, i);
    }
    return sum;
}


void test(){
    std::vector<std::vector<int> > v = {
        {1, 0, 2},
        {1, 2, 2}
    };

    std::vector<int> r = {5, 4};

    int size1 = v.size();
    int size2 = r.size();
    if ( size1 != size2) {
        printf("case case size unmatch!!! size %d size %d \n", size1, size2);
    }
    else{
        for (int i = 0; i < size1; i++) {
            int result = candy(v[i]);
            int expect = r[i];
            compare(i+1, result, expect);
        }
    }
}

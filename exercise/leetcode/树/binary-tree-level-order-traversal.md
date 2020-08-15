层次遍历

迭代版本

按照层级遍历， 每一层从左到右的顺序访问。 由于本层的左右顺序由 上一层的左右顺序决定， 先访问的节点， 其子节点也会先得到访问。 所以，使用一个队列，每访问一个节点， 其左右子节点就入队。 之后出队的顺序就是层级遍历的顺序。 

还有一个要求， 就是每一层的元素需要放在一起， 需要区分 什么时候是新的一层。  

使用 lvl 标记当前是第几层
用两个变量，curNum, nextNum, 标记本层和下层节点的数量。 

每从一个节点出队， 
curNum--;
if(curNum < 0){
    curNum = nextNum - 1;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        std::vector<std::vector<int> > v;
        if(root == nullptr) return v;

        queue<TreeNode*> q;
        q.push(root);
        int curNum = 0;
        int nextNum = 1;
        int lvl = -1;

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            curNum -= 1;
            
            if(curNum < 0){
                curNum = nextNum - 1;
                nextNum = 0;
                lvl +=1;
                // 新一层开始
                std::vector<int> t = {cur->val};
                v.push_back(t);
            }else{
                std::vector<int> t = v[lvl];
                t.push_back(cur->val);
                v[lvl] = t;
            }

            if(cur->left!=nullptr){
                nextNum +=1;
                q.push(cur->left);
            }

            if(cur->right!=nullptr){
                nextNum +=1;
                q.push(cur->right);
            }

        }

        return v;        
    }
};


也可以用两个队列来解决确定分层的问题
qCur, qNext 分别存放当前层和下一层的节点。

这样， 遍历当前层的元素，其子节点如qNext队列。 保存当前元素的值。 遍历完毕之后， 当前层的列表也得到。 加入结果即可。

这个版本代码更加简洁一点。 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        std::vector<std::vector<int> > v;
        if(root == nullptr) return v;

        queue<TreeNode*>qCur, qNext;
        qCur.push(root);

        while(!qCur.empty()){
            std::vector<int> curVec;
            while(!qCur.empty()){
                TreeNode* cur = qCur.front();
                qCur.pop();
                curVec.push_back(cur->val);
                if(cur->left!=nullptr) qNext.push(cur->left);
                if(cur->right!=nullptr) qNext.push(cur->right);
            }
            v.push_back(curVec);
            swap(qNext, qCur); // 这个函数很强。a copy construction and two assignment operations
        }

        return v;        
    }
};



递归的版本，

每遍历一个节点， 就把该节点的值写到结果中， 需要知道当前是第几层。 所以用层数当参数， 递归子节点时， 层数+1

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        std::vector<std::vector<int> > v;
        if(root == nullptr) return v;

        subLevelOrder(root, 0, v);
        return v;
    }

    void subLevelOrder(TreeNode* cur, int lvl, std::vector<std::vector<int> > &v){

        if(lvl<v.size()){
            std::vector<int> t = v[lvl];
            t.push_back(cur->val);
            v[lvl] = t;
        }else{
            std::vector<int> t = {cur->val};
            v.push_back(t);
        }

        if(cur->left!=nullptr)
            subLevelOrder(cur->left, lvl+1, v);

        if(cur->right!=nullptr)
            subLevelOrder(cur->right, lvl+1, v);
        
    }
};

代码很清晰，写起来也很顺畅。 这就是递归的好处。 但是效率明显下降。



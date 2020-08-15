

迭代式中序遍历二叉树


对于栈顶节点，如果左子节点为空或已被访问， 则栈顶需要访问并弹出。 否则按顺序压栈

用一个map来存放所有节点的访问情况。


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

    vector<int> inorderTraversal(TreeNode* root) {

        std::vector<int> v;
        if (root == nullptr) return v;

        std::map<TreeNode*, bool> M;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* cur = st.top();
            if(cur->left == nullptr || M.find(cur->left)!=M.end()){
                v.push_back(cur->val);
                st.pop();
                M[cur] = true;
                if(cur->right != nullptr) st.push(cur->right);
            }else{
                st.push(cur->left);
            }
        }

        return v;
    }
};


也可以不用map, 用一个指针p记录一个当前 节点， p初始指向根节点， 只要p不空就压入栈， 并执行其左子节点。
如果p为空, p指向栈顶，访问p， p指向 其右子节点。


class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {

        std::vector<int> v;
        if (root == nullptr) return v;

        stack<TreeNode*> st;
        TreeNode* p = root;

        while(!st.empty()||p!=nullptr) {
            if(p!=nullptr){
                st.push(p);
                p = p->left;
            }else{
                p = st.top();
                st.pop();
                v.push_back(p->val);
                p = p->right;
            }
        }

        return v;
    }
};


如果连栈也不给用， 需要标记遍历顺序。

           0
       1      2
     3   4   5  6
   7  8
 15 16

在中序遍历中， 一个节点cur 一定是在 其左子节点的最右子节点访问之后访问。这个最右子节点的右节点一定是空的， 我们找到这个最右子节点node, 标记  node -> right = cur;
    
这样， 每个节点的右侧节点都会指向一个节点。

确定一个节点什么时候需要访问
左子节点为空




class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {

        std::vector<int> v;
        if (root == nullptr) return v;

        TreeNode* cur = root;

        while(cur!=nullptr){
            if(cur->left == nullptr){
                v.push_back(cur->val);
                cur = cur -> right;
            }else{
                TreeNode* p = cur->left;
                while(p->right != nullptr && p->right != cur) p = p->right;
                
                if(p->right == nullptr){ // 还没有打标记，说明还没被访问，打上标记
                    p->right = cur;
                    cur = cur->left;
                }else{
                    v.push_back(cur->val); // 已经打上标记的， 说明当前节点的左侧节点都已经得到遍历， 可访问当前节点
                    p->right = nullptr; // 必须把标记取消掉， 不然 ac 不了....
                    cur = cur->right;
                }
            }
        }

        return v;
    }
};

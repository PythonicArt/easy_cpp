迭代式后序遍历二叉树

           0
       1      2
     3   4   5  6
   7  8
 15 16


遇到根节点， 先遍历左子节点， 在遍历右子节点， 最后再访问根节点。 

用一个辅助栈， 一个节点可能会两次入栈。 第一次是作为其他节点的子节点入栈， 第二次是自己被查看， 但是还有左右子节点。

也就意味着节点出栈的时候， 不一定就是要访问节点的时候。 
记录一个 lastVisit 指针， 则说明 自己的左右节点都已经访问完毕，

访问时机

左右子节点都为空|| 右子节点存在且 lastVisit为右子节点 || 左子节点存在 且 lastVisit 为左子节点




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
    vector<int> postorderTraversal(TreeNode* root) {
        
        std::vector<int> v;
        if(root == nullptr) return v;
        
        stack<TreeNode*> st;

        TreeNode* lastVisit = root;

        st.push(root);

        while(!st.empty()){

            TreeNode* cur = st.top();

            if((cur -> left == nullptr && cur -> right == nullptr)||
                (cur->right != nullptr && lastVisit == cur -> right)||
                (cur->left!=nullptr && lastVisit == cur -> left)){
                v.push_back(cur -> val);
                lastVisit = cur;
                st.pop();
            }else{
                if(cur -> right != nullptr) st.push(cur -> right);
                if(cur -> left != nullptr) st.push(cur -> left);
            }            

        }
        
        return v;

    }
};
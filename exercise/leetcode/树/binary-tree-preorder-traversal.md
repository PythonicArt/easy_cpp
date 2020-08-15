

迭代式前序遍历 二叉树



用数组表示的二叉树 子节点的获取

i
left_child: 2*i + 1
right_child 2*i + 2


用节点表示的二叉树直接读指针。


前序遍历指的是  依次访问 根节点，前序遍历左子节点， 前序遍历右子节点

由于在左子节点遍历前 右子节点已经被访问， 需要记住右子节点访问的顺序，这是迭代式解法的核心， 递归式解法由于递归的函数调用栈天然地就保存了调用的顺序。 

使用一个辅助的栈，用来模拟上述过程。 

           0
       1      2
     3   4   5  6
   7  8
 15 16

 我们需要保存  2 4 8 16 这个右子节点序列， 并且在左子节点返回时， 根据相反的顺序继续遍历。




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
    vector<int> preorderTraversal(TreeNode* root) {   
        
        std::vector<int> v;
        if(root == nullptr) return v;
        stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()){

            TreeNode* tmp = st.top();
            st.pop();
            v.push_back(tmp -> val);
            if(tmp -> right != nullptr) st.push(tmp -> right);
            if(tmp -> left != nullptr) st.push(tmp -> left);
        }

        return v;
        
    }
};



线索标记法

           0
       1      2
     3   4   5  6
   7  8
 15 16

 对每一个节点cur， 其左子节点的最右节点 p 访问完毕之后， 再访问cur的右节点。 所以， 提前打好标记 p->right = cur

每遇到一个节点 cur
    建立线索
    访问
    cur = cur->left

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

    
        


    }
};
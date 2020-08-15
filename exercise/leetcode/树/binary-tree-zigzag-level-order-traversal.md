之字形层次遍历，一层从左往右， 下一层从右往左， 依次循环

可以来一遍普通的， 再依次的去反转列表中的双数元素。 这应该不是想要的解法。


考虑递归的方式， 由于已经有层号， 如果是偶数层就前插， 而不是push_back




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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        std::vector<std::vector<int> > v;
        if(root == nullptr) return v;

        subLevelOrder(root, 0, v);
        return v;
    }

    void subLevelOrder(TreeNode* cur, int lvl, std::vector<std::vector<int> > &v){

        if(lvl>=v.size()){
            std::vector<int> t = {};
            v.push_back(t);
        }
        std::vector<int> t = v[lvl];
        if(lvl %2 ==0)
            t.push_back(cur->val);
        else
            t.insert(t.begin(), cur->val);

        v[lvl] = t;

        if(cur->left!=nullptr)
            subLevelOrder(cur->left, lvl+1, v);

        if(cur->right!=nullptr)
            subLevelOrder(cur->right, lvl+1, v);
        
    }
};
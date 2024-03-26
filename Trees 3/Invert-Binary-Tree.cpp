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
    void solve(TreeNode* r)
    {
        if(!r)return;
        TreeNode* a=r->left,*b=r->right;
        r->left=b;r->right=a;
        solve(r->left);
        solve(r->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode*x=root;
        solve(x);
        return root;
    }
};
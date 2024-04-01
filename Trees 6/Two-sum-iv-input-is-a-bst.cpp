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
    bool search(TreeNode* r,int d)
    {
        if(!r)return false;
        if(r->val==d)return true;
        if(r->val>d)return search(r->left,d);
        if(r->val<d)return search(r->right,d);
        return false;
    }
    bool solve(TreeNode* root,int k,TreeNode* r)
    {
        if(!root)return false;
        int d=root->val;
        int left=k-d;
        if(d*2!=k&&search(r,left))return true;
        return solve(root->left,k,r)||solve(root->right,k,r);
    }
    bool findTarget(TreeNode* root, int k) {
        return solve(root,k,root);
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) 
 * };
 */
class Solution {
public:
    long long solve(TreeNode* r,long long s,long long &f)
    {
        if(!r)return 0LL;
        if(r->val==s)f++;
        return 1LL+solve(r->left,s-r->val,f)+solve(r->right,s-r->val,f);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        long long ans=0,f=0;
        solve(root,1LL*targetSum,f);
        ans+=f;
        ans+=pathSum(root->left,targetSum);
        ans+=pathSum(root->right,targetSum);
        return ans;
    }
};
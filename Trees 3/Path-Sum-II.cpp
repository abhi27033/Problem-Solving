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
    vector<vector<int>> ans;
    void solve(TreeNode* r,int s,vector<int>& t)
    {
        if(!r)return;
        if(!r->left&&!r->right&&r->val==s)
        {
            t.push_back(r->val);
            ans.push_back(t);
            t.pop_back();
        }
        t.push_back(r->val);
        solve(r->left,s-r->val,t);
        solve(r->right,s-r->val,t);
        t.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> t;
        solve(root,targetSum,t);
        return ans;
    }
};
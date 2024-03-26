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
    vector<string> ans;
    void solve(TreeNode* r,string s)
    {
        if(!r)return;
        if(!r->left&&!r->right)
        {
            s+=to_string(r->val);
            ans.push_back(s);
            return;
        }
        s+=to_string(r->val);
        s+="->";
        solve(r->left,s);
        solve(r->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        solve(root,s);
        return ans;
    }
};
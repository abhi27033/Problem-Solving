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
TreeNode* solve(vector<int>& p,int l,int h)
{
    if(l>h)return NULL;
    if(l==h)return new TreeNode(p[l]);
    TreeNode* ans=new TreeNode(p[l]);
    int j=l+1;
    while(j<p.size()&&p[j]<=p[l])
    j++;
    ans->left=solve(p,l+1,j-1);
    ans->right=solve(p,j,h);
    return ans;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,0,preorder.size()-1);
    }
};
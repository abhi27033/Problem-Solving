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
    TreeNode* ele1,*ele2,*p=NULL;
    bool found;
    void solve(TreeNode* r)
    {
        if(!r)return;
        solve(r->left);
        if(p!=NULL)
        {
            // cout<<p->val<<" "<<r->val<<endl;
            if(p->val>r->val&&!found)
            {
                found=true;
                ele1=p;
                ele2=r;
            }
            else if(p->val>r->val&&found)
                ele2=r;
        }
         p=r;
        solve(r->right);
    }
    void recoverTree(TreeNode* root) {
        found=false;
        solve(root);
        int d=ele2->val;
        ele2->val=ele1->val;
        ele1->val=d;
    }
};
// 3 2 1
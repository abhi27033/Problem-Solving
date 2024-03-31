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
    int fi;
    struct dsa{
      bool isbst;
      int mi,ma,su;
        dsa()
        {
            isbst=true;
            mi=INT_MAX,ma=INT_MIN;
            su=0;
        }
    };
    dsa solve(TreeNode* r)
    {
        if(!r)return dsa();
        dsa l=solve(r->left);
        dsa rr=solve(r->right);
        if(l.isbst&&rr.isbst&&l.ma<r->val&&rr.mi>r->val)
        {
            dsa ans;
            ans.isbst=true;
            ans.mi=min(l.mi,r->val);
            ans.ma=max(rr.ma,r->val);
            ans.su=l.su+rr.su+r->val;
            fi=max({fi,l.su,rr.su,ans.su});
            return ans;
        }
        else
        {
            dsa ans;
            ans.isbst=false;
            ans.mi=INT_MIN;
            ans.ma=INT_MAX;
            ans.su=max({0,l.su,rr.su});
            fi=max(fi,ans.su);
            return ans;
        }
    }
    int maxSumBST(TreeNode* root) {
        fi=0;
        solve(root).su;
        return fi;
    }
};
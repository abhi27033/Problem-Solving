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

    TreeNode* solve(TreeNode* r,int s,int e)
    {
       if(!r||r->val==s||r->val==e)
           return r;
        TreeNode* a=solve(r->left,s,e);
        TreeNode* b=solve(r->right,s,e);
        if(a&&b)return r;
        if(a)return a;
        return b;
    }
    string f1="",ff="";
    void s1(TreeNode* r,int f,string& a)
    {
        if(!r)return;
        if(r->val==f)
        {
            f1=a;
            return;
        }
        a+='U';
        s1(r->left,f,a);
        s1(r->right,f,a);
        a.pop_back();
    }
    void s2(TreeNode* r,int f,string& b)
    {
        if(!r)return;
        if(r->val==f)
        {
            ff=b;
            return;
        }
        b+='L';
        s2(r->left,f,b);
        b.pop_back();
        b+='R';
        s2(r->right,f,b);
        b.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* temp=solve(root,startValue,destValue);
        string a="",b="";
        TreeNode* x=temp;
        s1(x,startValue,a);
        s2(temp,destValue,b);
        return f1+ff;    
        }
};
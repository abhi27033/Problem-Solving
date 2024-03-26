/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<int> ans,fin;
 void solv(TreeNode* r,int b)
 {
     if(!r)return;
     if(r->val==b)
     {
         ans.push_back(b);
         fin=ans;
         ans.pop_back();
         return;
     }
     ans.push_back(r->val);
     solv(r->left,b);
     solv(r->right,b);
     ans.pop_back();
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    solv(A,B);
    return fin;
}

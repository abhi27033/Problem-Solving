/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
TreeNode* solve(ListNode* h)
{
    if(!h)return NULL;
    ListNode* sl=h,*fa=h,*p=NULL;
    while(fa&&fa->next)
    {
        p=sl;
        sl=sl->next;
        fa=fa->next->next;
    }
    if(p)
    p->next=NULL;
    else
    h=NULL;
    int d=sl->val;
    TreeNode* ans=new TreeNode(d);
    ans->left=solve(h);
    ans->right=solve(sl->next);
    return ans;
}
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head);
    }
};
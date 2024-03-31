/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
struct dsa{
  bool isbst;
  int mi,ma,si;
  dsa(){
      isbst=true;
      mi=INT_MAX;
      ma=INT_MIN;
      si=0;
  }
};
dsa solve(Node* root)
{
    if(!root)return dsa();
    dsa l=solve(root->left);
    dsa r=solve(root->right);
    if(l.isbst&&r.isbst&&l.ma<root->data&&root->data<r.mi)
    {
        dsa ans;
        ans.isbst=true;
        ans.si=1+l.si+r.si;
        ans.mi=min(root->data,l.mi);
        ans.ma=max(root->data,r.ma);
        return ans;
    }
    else
    {
        dsa ans;
        ans.isbst=true;
        ans.mi=INT_MIN;
        ans.ma=INT_MAX;
        ans.si=max(l.si,r.si);
        return ans;
    }
}
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	return solve(root).si;
    }
};
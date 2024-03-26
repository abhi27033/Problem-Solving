vector<int> ans;
void solve(BinaryTreeNode<int>* r,int x)
{
    if(!r)return ;
    if(ans.size()<x+1)
    ans.push_back(r->data);
    solve(r->left,x+1);
    solve(r->right,x+1);
}
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    solve(root,0);
    return ans;
}
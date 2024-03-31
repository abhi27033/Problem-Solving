vector<int> ans,v;
int flg;
void lsol(TreeNode<int>* r)
{
    if(!r)return;
    if (!r->left && !r->right) {
      flg = 1;
      return;
    }
    if(flg==-1)
    ans.push_back(r->data);
    lsol(r->left); 
    lsol(r->right);
}
void solve(TreeNode<int>* r)
{
    if(!r)return;
    solve(r->left);
    if(!r->left&&!r->right)
    {
        //leaf
        ans.push_back(r->data);
    }
    solve(r->right);
}

void rsol(TreeNode<int>* r)
{
    if(!r)return;
     if (!r->left && !r->right) {
      flg = 1;
      return;
    }
    if(flg==-1)
    v.push_back(r->data);
    rsol(r->right);
    rsol(r->left);
}
vector<int> traverseBoundary(TreeNode<int> *roo)
{
	// Write your code here.
    TreeNode<int>* root=roo;
    ans.push_back(root->data);
    flg=-1;
    lsol(root->left);
    root=roo;
    solve(root);
    root=roo;
    flg=-1;
    rsol(root->right);
    reverse(v.begin(),v.end());
    for(auto it:v)
    ans.push_back(it);
    return ans;
}

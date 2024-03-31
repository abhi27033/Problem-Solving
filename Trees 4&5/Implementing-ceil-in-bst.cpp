
int ans=-1;
void solve(Node* r,int x)
{
    if(!r)return;
    if(r->data>=x)
    {
    ans=r->data;
    solve(r->left,x);
    }
    else
    solve(r->right,x);
}
// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    solve(root,input);
    return ans;
    // Your code here
}
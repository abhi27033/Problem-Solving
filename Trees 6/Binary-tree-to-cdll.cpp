/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node* tail=NULL,*p=NULL,*head=NULL;
    void solve(Node* r)
    {
        if(!r)return;
        solve(r->left);
        r->left=p;
        if(p)
        p->right=r;
        else
        head=r;
        tail=r;
        p=r;
        solve(r->right);
    }
    Node *bTreeToCList(Node *root)
    {
    //add code here.
    solve(root);
    head->left=tail;
    tail->right=head;
    return head;
    }
};
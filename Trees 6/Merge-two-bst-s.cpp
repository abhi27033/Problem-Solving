/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void ino(Node* r,vector<int>& a)
    {
        if(!r)return;
        ino(r->left,a);
        a.push_back(r->data);
        ino(r->right,a);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> a,b;
       ino(root1,a);
       ino(root2,b);
       vector<int> ans;
       int i=0,j=0,n=a.size(),m=b.size();
       while(i<n&&j<m)
       {
           if(a[i]<b[j])
               ans.push_back(a[i++]);
           else
               ans.push_back(b[j++]);
       }
       while(i<n)
       ans.push_back(a[i++]);
       while(j<m)
       ans.push_back(b[j++]);
       return ans;
    }
};
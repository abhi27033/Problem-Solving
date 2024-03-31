class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector<int> ans;
    unordered_map<int,int> mp;
    void chk(Node* r)
    {
        if(!r)return ;
        mp[r->data]++;
        chk(r->left);
        chk(r->right);
    }
    void solve(Node* a,Node* b)
    {
        if(!a)return;
        solve(a->left,b);
        if(mp.find(a->data)!=mp.end())ans.push_back(a->data);
        solve(a->right,b);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     chk(root2);
     solve(root1,root2);
     mp.clear();
     return ans;
    }
};

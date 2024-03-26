class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node* r,int a,int b)
    {
        if(!r||r->data==a||r->data==b)
        return r;
        Node* i=lca(r->left,a,b);
        Node* j=lca(r->right,a,b);
        if(i&&j)return r;
        if(i)return i;
        return j;
    }
    int dis(Node* r,int v)
    {
        if(!r)return 10000;
        if(r->data==v)return 0;
        return 1+min(dis(r->left,v),dis(r->right,v));
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* x=lca(root,a,b);
        Node*xx=x;
        return dis(x,a)+dis(xx,b);
    }
};
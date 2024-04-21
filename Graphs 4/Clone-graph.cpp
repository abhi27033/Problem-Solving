/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node* r,unordered_map<int,Node*>& vis)
    {
        if(!r)return NULL;
        Node* t=new Node(r->val);
        vis[r->val]=(t);
        for(auto it:r->neighbors)
        {
            if(vis.find(it->val)==vis.end())
                t->neighbors.push_back(clone(it,vis));
            else
                 t->neighbors.push_back(vis[it->val]);
        }
        return t;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*> vis;
        return clone(node,vis);
    }
};
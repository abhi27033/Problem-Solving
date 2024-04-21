class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> adj[],vector<int>& vis)
    {
        //0 ->unvisited 1->in stack 2->visited
        if(vis[node]==1)return true;
        if(vis[node]==2)return false;
        vis[node]=1;
        bool flg=false;
        for(auto it:adj[node])
            flg|=dfs(it,adj,vis);
        vis[node]=2;
        return flg;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        if(dfs(i,adj,vis))return true;
        return false;
    }
};
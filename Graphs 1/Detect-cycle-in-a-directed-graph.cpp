class Solution {
  public:
  bool dfs(vector<int> adj[],int node,vector<int>& vis)
  {
      if(vis[node]==1)return false;
      vis[node]=0;//go in stack
      bool flg=false;
      for(auto it:adj[node])
      {
          if(vis[it]==0)return true;
          else flg|=dfs(adj,it,vis);
      }
      vis[node]=1;
      return flg;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,-1);
        //-1 for unvisited 0 for in stack 1 for completely visited
        for(int i=0;i<V;i++)
        {
            if(vis[i]==-1&&dfs(adj,i,vis))
            return true;
        }
        return false;
    }
};
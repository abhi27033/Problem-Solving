class Solution {
public:
    void dfs(vector<vector<int>>& adj,int n,vector<int>& vis)
    {
        if(vis[n]==1)return;
        vis[n]=1;
        for(int i=0;i<adj[n].size();i++)
        {
            if(adj[n][i]==1)
            dfs(adj,i,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),m=isConnected[0].size();
        vector<int> vis(n,-1);
        int c=0;
        for(int i=0;i<n;i++)
        {
                if(vis[i]==-1)
                {
                    dfs(isConnected,i,vis);
                    c++;
                }
        }
        return c;
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        vector<int> vis(n,-1);
        q.push(source);
        vis[source]=1;
        while(q.size())
        {
            int t=q.front();
            q.pop();
            if(t==destination)return true;
            for(auto it:adj[t])
            {
                if(vis[it]==-1)
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            vector<int> dist(n,INT_MAX),par(n,-1);
            queue<int> q;
            q.push(i);
            dist[i]=0;
            while(q.size())
            {
                int node=q.front();
                q.pop();
                for(auto it:adj[node])
                {
                    if(dist[it]==INT_MAX)
                    {
                        par[it]=node;
                        dist[it]=dist[node]+1;
                        q.push(it);
                    }
                    else if(par[node]!=it)
                        ans=min(ans,dist[it]+dist[node]+1);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

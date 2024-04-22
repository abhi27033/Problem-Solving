class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& s, int start, int end) 
    {
        vector<vector<pair<double,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            auto it=edges[i];
            adj[it[0]].push_back({it[1],s[i]});
            adj[it[1]].push_back({it[0],s[i]});
        }
        vector<double>dist(n,INT_MIN);
        vector<int> vis(n, -1);
        dist[start]=1.0;
        priority_queue<pair<double,double>> pq;
        pq.push({1.0,start});
        while(pq.size())
        {
            auto it=pq.top();
            pq.pop();
            double node=it.second;
            double d=it.first;
            if( vis[node]==1)
                continue;
            vis[node] = 1;
            for(auto it:adj[node])
            {
                if(dist[it.first]<=dist[node]*it.second)
                {
                    dist[it.first]=dist[node]*it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return dist[end]==INT_MIN?0:dist[end];
    }
};

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> dis(n,-1);
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> di(n,INT_MAX);
        vector<int> vis(n, -1);
        di[0]=0;
        pq.push({0,0});
        while(pq.size())
        {
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int node=it.second;
            if( vis[node]==1)
                continue;
            vis[node] = 1;
            for(auto itt:adj[node])
            {
                if(disappear[itt.first]>d+itt.second&&di[itt.first]>di[node]+itt.second)
                {
                   di[itt.first]=di[node]+itt.second;
                   pq.push({di[itt.first],itt.first});
                }
            }
        }
        for(int i=0;i<n;i++)
        di[i]=di[i]>=INT_MAX?-1:di[i];
        return di;
    }
};
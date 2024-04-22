class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:times)
            adj[it[0]-1].push_back({it[1]-1,it[2]});
        vector<int> vis(n,-1);
        vector<int> dist(n,INT_MAX);
        dist[k-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k-1});
        while(pq.size())
        {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            if(vis[node]==1)continue;
            vis[node]=1;
            for(auto it:adj[node])
            {
                if(dist[it.first]>dist[node]+it.second)
                {
                    dist[it.first]=dist[node]+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        for(auto it:dist)
        if(it==INT_MAX)return-1;
        int ans=INT_MIN;
        for(auto it:dist)
        ans=max(ans,it);
        return ans;
    }
};
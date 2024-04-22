class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights)
        adj[it[0]].push_back({it[1],it[2]});
        pq.push({0,0,src});
        k++;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        while(pq.size())
        {
            int kk=pq.top()[0];
            int dis=pq.top()[1];
            int node=pq.top()[2];
            pq.pop();
            if(kk>=k)continue;
            for(auto it:adj[node])
            {
                if(dist[it.first]>dis+it.second)
                {
                    dist[it.first]=dis+it.second;
                    pq.push({kk+1,dist[it.first],it.first});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
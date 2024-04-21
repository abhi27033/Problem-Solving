class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            src--;
            dst--;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,src});
            vector<vector<int>> adj(n);
            vector<vector<int>> rev(n);
            for(auto it:edges)
            {
                adj[it[0]-1].push_back(it[1]-1);
                rev[it[1]-1].push_back(it[0]-1);
            }
            set<pair<int,int>> vis;
            vis.insert({src,1});
            vis.insert({src,2});
            while(pq.size())
            {
                auto it=pq.top();
                pq.pop();
                int node=it.second;
                int cost=it.first;
                if(node==dst)
                return cost;
                for(auto it:adj[node])
                {
                    if(vis.find({it,1})==vis.end())
                    {
                        vis.insert({it,1});
                        pq.push({cost,it});
                    }
                }
                for(auto it:rev[node])
                {
                    if(vis.find({it,2})==vis.end())
                    {
                        vis.insert({it,2});
                        pq.push({cost+1,it});
                    }
                }
            }
            return -1;
        }
};
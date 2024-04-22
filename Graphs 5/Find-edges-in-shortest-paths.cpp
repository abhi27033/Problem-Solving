class Solution {
public:
vector<int> dijkitras(int n,vector<vector<pair<int,int>>>& adj,int src)
{
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> di(n,1e7);
        vector<int> vis(n, -1);
        di[src]=0;
        pq.push({0,src});
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
                if(di[itt.first]>d+itt.second)
                {
                   di[itt.first]=d+itt.second;
                   pq.push({di[itt.first],itt.first});
                }
            }
        }
        return  di;
}
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> src=dijkitras(n,adj,0);
        vector<int> dst=dijkitras(n,adj,n-1);
        int e=edges.size(),shortest=src[n-1];
        vector<bool> ans(e,false);
        for(int i=0;i<e;i++)
        {
            int u=edges[i][0],v=edges[i][1],w=edges[i][2];
            if((src[u]+dst[v]+w==shortest)||(src[v]+dst[u]+w==shortest))
            ans[i]=true;
        }
        return ans;
    }
};
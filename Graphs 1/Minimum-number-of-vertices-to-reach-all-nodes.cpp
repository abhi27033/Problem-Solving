class Solution {
public:
    void dfs(int n,vector<int>& vis,vector<vector<int>>& adj)
    {
        if(vis[n]==1)
            return;
        vis[n]=1;
        for(auto it:adj[n])
        dfs(it,vis,adj);
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        vector<pair<int,int>> pq;
        for(int i=0;i<n;i++)
            pq.push_back({ind[i],i});
        sort(pq.begin(),pq.end());
        vector<int> ans;
        vector<int> vis(n,-1);
        for(auto it:pq)
        {
            int node=it.second;
            if(vis[node]==-1)
            {
                ans.push_back(node);
                dfs(node,vis,adj);
            }
        }
        return ans;
    }
};

//alternatively can count indegrees only

// class Solution {
// public:
//     vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
//         vector<int> ans;
//         unordered_map<int,int> mp;
//         for(auto it:edges)
//         {
//             mp[it[1]]++;
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(mp.find(i)==mp.end())
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(auto it:edges)
        {
            indeg[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        queue<int> q;
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                vis[i]=1;
            }
        }
        vector<set<int>> ans(n);
        while(q.size())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                for(auto itt:ans[node])
                    ans[it].insert(itt);
                ans[it].insert(node);
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        vector<vector<int>> fin(n);
        for(int i=0;i<n;i++)
        {
            for(auto itt:ans[i])
                fin[i].push_back(itt);
        }
        return fin;
    }
};
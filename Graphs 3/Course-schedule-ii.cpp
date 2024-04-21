class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(auto it:p)
        {
            indeg[it[0]]++;
            adj[it[1]].push_back(it[0]);
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
        vector<int> ans;
        while(q.size())
        {
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto it:adj[t])
            {
                indeg[it]--;
                if(indeg[it]==0)
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
            
        }
        if(ans.size()==n)
        return ans;
        return {};
    }
};
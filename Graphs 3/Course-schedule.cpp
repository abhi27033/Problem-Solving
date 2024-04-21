class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
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
        while(q.size())
        {
            int t=q.front();
            q.pop();
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
        for(auto it:vis)
            if(it==-1)return false;
        return true;
    }
};
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        queue<int> q;
        vector<int> vis(n,-1);
        vector<vector<int>> c(n,vector<int>(26,0));
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                c[i][colors[i]-'a']++;
                q.push(i);
                vis[i]=1;
            }
        }
        int ans=0;
        while(q.size())
        {
            int t=q.front();
            q.pop();
            int ma=0;
            for(auto it:c[t])
                ma=max(ma,it);
            ans=max(ans,ma);
            for(auto it:adj[t])
            {
                for(int i=0;i<26;i++)
                    c[it][i]=max(c[it][i],c[t][i]+(colors[it]-'a'==i));
                indeg[it]--;
                if(indeg[it]==0)
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        for(auto it:vis)
            if(it==-1)return -1;
        return ans;
    }
};
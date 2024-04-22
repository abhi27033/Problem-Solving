class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,1e7));
        for(int i=0;i<n;i++)adj[i][i]=0;
        for(auto it:edges)
        {
            adj[it[0]][it[1]]=it[2];
            adj[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
        int mi=INT_MAX,midx=-1;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(auto it:adj[i])
            cnt+=it<=distanceThreshold;
            if(mi>=cnt)
            {
                mi=cnt;
                midx=i;
            }
        }
        return midx;
    }
};
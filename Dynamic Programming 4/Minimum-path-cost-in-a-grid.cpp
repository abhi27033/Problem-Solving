class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<m;i++)
            dp[n-1][i]=grid[n-1][i];
        int ans=INT_MAX;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    dp[i][j]=min(dp[i][j],grid[i][j]+moveCost[grid[i][j]][k]+dp[i+1][k]);
                    if(i==0)
                        ans=min(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};
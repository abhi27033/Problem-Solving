class Solution {
public:
    vector<vector<int>> dp;
    // int solve(int i,int j,vector<vector<int>>& ar)
    // {
    //     if(i>=ar.size()||j>=ar[0].size())
    //         return 1e7;
    //     if(i==ar.size()-1&&j==ar[0].size()-1)return ar[i][j];
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     return dp[i][j]=ar[i][j]+min(solve(i+1,j,ar),solve(i,j+1,ar));
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        dp.resize(n+1,vector<int>(m+1,1e7));
        dp[n-1][m-1]=grid[n-1][m-1];
        // return solve(0,0,grid);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(!(i==n-1&&j==m-1))
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
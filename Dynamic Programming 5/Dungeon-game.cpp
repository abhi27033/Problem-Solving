class Solution {
public:
// vector<vector<int>> dp;
// int solve(vector<vector<int>>& d,int i,int j)
// {
//     int n=d.size(),m=d[0].size();
//     if(i>=n||j>=m)return 1e9;
//     if(i==n-1&&j==m-1)return d[i][j]>0?1:-1*d[i][j]+1;
//     if(dp[i][j]!=-1)return dp[i][j];
//     int a=solve(d,i+1,j)-d[i][j];
//     int b=solve(d,i,j+1)-d[i][j];
//     int c=min(a,b);
//     return dp[i][j]=(c<=0)?1:c;
// }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        // dp.resize(n+1,vector<int>(m+1,1e9));
        // return solve(dungeon,0,0);
        // dp[n-1][m-1]=(dungeon[n-1][m-1]>0)?1:(-1*dungeon[n-1][m-1]+1);
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=m-1;j>=0;j--)
        //     {
        //         if(i==n-1&&j==m-1)continue;
        //         int a=dp[i+1][j]-dungeon[i][j];
        //         int b=dp[i][j+1]-dungeon[i][j];
        //         int c=min(a,b);
        //         dp[i][j]=(c<=0)?1:c;
        //     }
        // }
        // return dp[0][0];
        vector<int> dp(m + 1, 1e7); // Using 1D array instead of 2D
        dp[m - 1] = dungeon[n - 1][m - 1] > 0 ? 1 : (-dungeon[n - 1][m - 1] + 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1) continue;
            int a = dp[j] - dungeon[i][j];
            int b = dp[j + 1] - dungeon[i][j];
            int c = min(a, b);
            dp[j] = c <= 0 ? 1 : c;
            }
        }
        return dp[0];
    }
};
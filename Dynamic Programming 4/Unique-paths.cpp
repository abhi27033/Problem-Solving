class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(int i,int j,int& m,int& n)
    // {
    //     if(i>=m||j>=n)return 0;
    //     if(i==m-1&&j==n-1)return 1;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     return dp[i][j]=solve(i+1,j,m,n)+solve(i,j+1,m,n);
    // }
    int ncr(int n,int r)
    {
        long long int ans=1;
        for(int i=1;i<=r;i++)
            ans=(ans*(n-r+i))/(i);
        return ans;
    }
    int uniquePaths(int m, int n) {
        // dp.resize(m+1,vector<int>(n+1,0));
        // dp[m-1][n-1]=1;
        // for(int i=m-1;i>=0;i--)
        // {
        //     for(int j=n-1;j>=0;j--)
        //     {
        //         if(!(i==m-1&&j==n-1))
        //         dp[i][j]=dp[i+1][j]+dp[i][j+1];
        //     }
        // }
        // return dp[0][0];
        //can use combinatorics i.e m+n-2Cn-1
        int N=m+n-2;
        int R=m-1;
        return ncr(N,R);
    }
};
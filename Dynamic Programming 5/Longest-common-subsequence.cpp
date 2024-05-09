class Solution {
public:
    vector<vector<int>> dp;
    // int solve(string& t1,string& t2,int i,int j)
    // {
    //     if(i>=t1.size()||j>=t2.size())return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(t1[i]==t2[j])return 1+solve(t1,t2,i+1,j+1);
    //     return dp[i][j]=max(solve(t1,t2,i+1,j),solve(t1,t2,i,j+1));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        // dp.resize(n+1,vector<int>(m+1,0));
        // return solve(text1,text2,0,0);
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=m-1;j>=0;j--)
        //     {
        //         if(text1[i]==text2[j])
        //         dp[i][j]=1+dp[i+1][j+1];
        //         else
        //         dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        //     }
        // }
        // return dp[0][0];
        vector<int> pdp(m+1,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int> dp(m+1,0);
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                dp[j]=1+pdp[j+1];
                else
                dp[j]=max(pdp[j],dp[j+1]);
            }
            pdp=dp;
        }
        return pdp[0];
    }
};
class Solution {
public:
    vector<vector<int>> dp;
    // int solve(vector<int>& ar,int i,int amt)
    // {
    //     if(i>=ar.size()||amt<0)return 0;
    //     if(amt==0)return 1;
    //     if(dp[i][amt]!=-1)return dp[i][amt];
    //     int pick=solve(ar,i,amt-ar[i]);
    //     int npick=solve(ar,i+1,amt);
    //     return dp[i][amt]=pick+npick;
    // }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.resize(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        // return solve(coins,0,amount);
        for(int i=n-1;i>=0;i--)
        {
            for(int amt=0;amt<=amount;amt++)
            {
                int pick=0,npick=0;
                if(amt-coins[i]>=0)
                pick=dp[i][amt-coins[i]];
                if(i+1<=n)
                npick=dp[i+1][amt];
                dp[i][amt]=pick+npick;
            }
        }
        return dp[0][amount];
    }
};
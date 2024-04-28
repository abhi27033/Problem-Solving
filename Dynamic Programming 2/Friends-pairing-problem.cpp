class Solution
{
public:
int*dp;
const int mod=1e9+7;
int solve(int n)
{
    if(n<=0)return n==0;
    if(dp[n]!=-1)return dp[n]%mod;
    return dp[n]=((solve(n-1)%mod)+(1LL*(n-1)*solve(n-2)%mod)%mod)%mod;
}
    int countFriendsPairings(int n) 
    { 
        dp=new int[n+1];
        memset(dp,-1,(n+1)*sizeof(int));
        return solve(n)%mod;
    }
};    
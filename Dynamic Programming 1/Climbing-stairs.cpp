class Solution {
public:
int dp[50];
int climbStair(int n)
{
        if(n<=0)return n==0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=climbStair(n-2)+climbStair(n-1);
}
    int climbStairs(int n) {
        memset(dp,-1,50*sizeof(int));
        return climbStair(n);
    }
};
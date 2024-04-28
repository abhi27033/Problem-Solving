class Solution {
public:
vector<vector<int>> dp;
int solve(int s,int i)
{
    if(s<=0||i*i>s)return s==0?0:100009;
    if(dp[s][i]!=-1)return dp[s][i];
    int a=1+solve(s-i*i,i);
    int b=solve(s,i+1);
    return dp[s][i]=min(a,b);
}
    int numSquares(int n) {
        dp.resize(n+1,vector<int>(sqrt(n)+1,-1));
        return solve(n,1);
    }
};
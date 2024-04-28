class Solution{
public:
int dp[10001][2];
int solve(int i,int fs,vector<vector<int>>&mat)
{
    if(i>=mat[0].size())return 0;
    if(dp[i][fs]!=-1)return dp[i][fs];
    int pick=mat[fs][i]+max(solve(i+2,fs,mat),solve(i+2,fs^1,mat));
    int npick=solve(i+1,fs,mat);
    return dp[i][fs]=max(pick,npick);
}
    int maxSum(int N, vector<vector<int>> mat)
    {
        for(int i=0;i<=N;i++)
        for(int j=0;j<2;j++)
        dp[i][j]=-1;
        return max(solve(0,0,mat),solve(0,1,mat));
    }
};
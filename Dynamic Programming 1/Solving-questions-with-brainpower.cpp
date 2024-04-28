class Solution {
public:
long long *dp;
long long solve(vector<vector<int>>& q,int i)
{
    if(i>=q.size())return 0;
    if(dp[i]!=-1LL)return dp[i];
    long long pick=q[i][0]+solve(q,i+q[i][1]+1);
    long long npick=solve(q,i+1);
    return dp[i]=max(pick,npick);
}
    long long mostPoints(vector<vector<int>>& questions) {
        dp=new long long[questions.size()];
        memset(dp,-1LL,questions.size()*sizeof(long long));
        return solve(questions,0);
    }
};
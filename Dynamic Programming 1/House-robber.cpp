class Solution {
public:
int* dp;
int solve(vector<int>& ar,int i)
{
    if(i>=ar.size())return 0;
    if(dp[i]!=-1)return dp[i];
    return dp[i]=max(ar[i]+solve(ar,i+2),solve(ar,i+1));
}
    int rob(vector<int>& nums) {
        dp=new int[nums.size()];
        memset(dp,-1,nums.size()*sizeof(int));
        return solve(nums,0);
    }
};
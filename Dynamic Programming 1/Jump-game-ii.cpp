class Solution {
public:
int* dp;
int solve(vector<int>& ar,int idx)
{
    if(idx>=ar.size()-1)return idx==ar.size()-1?0:10009;
    if(dp[idx]!=-1)return dp[idx];
    int ans=10009;
    for(int i=idx+1;i<=idx+ar[idx];i++)
    ans=min(ans,1+solve(ar,i));
    return dp[idx]=ans;
}
    int jump(vector<int>& nums) {
        dp=new int[nums.size()];
        memset(dp,-1,nums.size()*sizeof(int));
        return solve(nums,0);
    }
};
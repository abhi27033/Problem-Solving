class Solution {
public:
int* dp;
int solve(vector<int>& ar,int i,int n)
{
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    return dp[i]=max(ar[i]+solve(ar,i+2,n),solve(ar,i+1,n));
}
    int rob(vector<int>& nums) {
        dp=new int[nums.size()];
        if(nums.size()==1)return nums[0];
        memset(dp,-1,nums.size()*sizeof(int));
        int a=solve(nums,0,nums.size()-1);
        memset(dp,-1,nums.size()*sizeof(int));
        int b=solve(nums,1,nums.size());
        return max(a,b);
    }
};
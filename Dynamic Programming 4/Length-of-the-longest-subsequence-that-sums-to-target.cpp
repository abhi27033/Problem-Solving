class Solution {
public:
    vector<vector<int>> dp;
    // int solve(vector<int>& ar,int t,int i)
    // {
    //     if(t==0)return 0;
    //     if(i>=ar.size()||t<0)return -1e6;
    //     if(dp[i][t]!=-1)return dp[i][t];
    //     int pick=1+solve(ar,t-ar[i],i+1);
    //     int npick=solve(ar,t,i+1);
    //     return dp[i][t]=max(pick,npick);
    // }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(target+1,-1e6));
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int t=0;t<=target;t++)
            {
                int pick=-1e6,npick=-1e6;
                if(t-nums[i]>=0)
                    pick=1+dp[i+1][t-nums[i]];
                npick=dp[i+1][t];
                dp[i][t]=max(pick,npick);
            }
        }
        int x=dp[0][target];
        return x<0?-1:x;
    }
};
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> len(n,1);
        int mx=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        len[i]=len[j];
                        mx=max(mx,dp[i]);
                    }
                    else if(dp[i]==dp[j]+1)
                        len[i]+=len[j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            if(dp[i]==mx)
                ans+=len[i];
        return ans;
    }
};
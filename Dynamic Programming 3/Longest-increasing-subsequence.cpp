class Solution {
public:
    // vector<int> dp;
    // int glans=1;
    // int solve(vector<int>& ar,int idx)
    // {
    //     if(idx>=ar.size())return 0;
    //     if(dp[idx]!=-1)return dp[idx];
    //     int ele=ar[idx];
    //     int ans=1;
    //     for(int i=idx+1;i<ar.size();i++)
    //     {
    //         if(ar[i]>ele)
    //         ans=max(ans,1+solve(ar,i));
    //     }
    //     glans=max(glans,ans);
    //     glans=max(glans,solve(ar,idx+1));
    //     return dp[idx]=ans;
    // }
    int lengthOfLIS(vector<int>& nums) {
        // int n=nums.size();
        // dp.resize(n+1,1);
        // solve(nums,0);
        // for(int i=n-1;i>=0;i--)
        // {
        //     int ans=1;
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(nums[j]>nums[i])
        //             ans=max(ans,1+dp[j]);
        //     }
        //     glans=max(glans,ans);
        //     glans=max(glans,dp[i+1]);
        //     dp[i]=ans;
        // }
        // return glans;
        vector<int> ans;
        for(auto it:nums)
        {
            if(ans.size()==0||ans[ans.size()-1]<it)
                ans.push_back(it);
            else
            {
                auto lb=lower_bound(ans.begin(),ans.end(),it);
                *lb=it;
            }
        }
        return ans.size();
    }
};
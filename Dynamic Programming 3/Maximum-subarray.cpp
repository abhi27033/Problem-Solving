class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN,su=0;
        for(auto it:nums)
        {
            su+=it;
            ans=max(ans,su);
            if(su<0)
                su=0;
        }
        return ans;
    }
};
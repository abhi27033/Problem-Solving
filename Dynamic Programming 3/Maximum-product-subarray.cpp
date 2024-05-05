class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int f=1;
        for(auto it:nums)
        {
            f*=it;
            ans=max(ans,f);
            if(f==0)
                f=1;
        }
        f=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            f*=nums[i];
            ans=max(ans,f);
            if(f==0)
                f=1;
        }
        return ans;
    }
};
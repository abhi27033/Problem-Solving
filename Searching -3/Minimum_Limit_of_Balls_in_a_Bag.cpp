class Solution {
public:
bool ispossible(int m,int mo,vector<int>& ar)
{
    int ans=0;
    for(auto it:ar)
    {
        if(it>m)
        {
            double q=it;
            q=ceil(q/m)-1;
            ans+=q;
        }
    }
    return ans<=mo;
}
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,h=-1e9;
        for(auto it:nums)
        h=max(h,it);
        int ans=1;
        sort(nums.rbegin(),nums.rend());
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(ispossible(m,maxOperations,nums))
            {
                ans=m;
                h=m-1;
            }
            else
            l=m+1;
        }
        return ans;
    }
};
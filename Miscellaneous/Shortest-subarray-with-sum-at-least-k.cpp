class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long,long long>> dq;
        long long ans=INT_MAX,s=0;
        for(long long i=0;i<nums.size();i++)
        {
            s+=nums[i];
            if(s>=k)
                ans=min(ans,i+1);
            pair<long long,long long> p={-1,-1};
            while(dq.size()&&s-dq.back().second>=k)
            {
                p=dq.back();
                dq.pop_back();
            }
            if(p.first!=-1)
                ans=min(ans,i-p.first);
            while(dq.size()&&dq.front().second>=s)
                dq.pop_front();
            dq.push_front({i,s});
        }
        return ans==INT_MAX?-1:ans;
    }
};
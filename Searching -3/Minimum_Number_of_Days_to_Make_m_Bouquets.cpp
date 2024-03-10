class Solution {
public:
bool ispossible(int day,vector<int>&ar,int k,int m)
{
    int c=0,q=0;
    for(int i=0;i<ar.size();i++)
    {
        if(ar[i]<=day)
        {
            c++;
            if(c==k)
            {
            q++;
            c=0;
            }
        }
        else
        c=0;
    }
    return q>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=INT_MAX,h=INT_MIN;
        for(auto it:bloomDay)
        {
            l=min(l,it);
            h=max(h,it);
        }
        int ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(ispossible(mid,bloomDay,k,m))
            {
                ans=mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};
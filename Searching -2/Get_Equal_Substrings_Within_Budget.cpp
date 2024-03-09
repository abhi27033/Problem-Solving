class Solution {
public:
bool ispossible(int len,int maxcos,vector<int>& diff)
{
    for(int i=len-1;i<diff.size();i++)
    {
        int t=diff[i];
        if(i>=len)
        t-=diff[i-len];
        if(t<=maxcos)
        return true;
    }
    return false;
}
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff;
        for(int i=0;i<s.size();i++)
        {
            int a=s[i]-'a';
            int b=t[i]-'a';
            a=abs(a-b);
            diff.push_back(a);
        }
        for(int i=1;i<diff.size();i++)
        diff[i]+=diff[i-1];
        int l=1,h=s.size(),ans=0;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(ispossible(m,maxCost,diff))
            {
                ans=m;
                l=m+1;
            }
            else
            h=m-1;
        }
        return ans;
    }
};
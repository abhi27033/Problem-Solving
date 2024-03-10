
bool ispossible(int t,vector<int>& ar,int k)
{
    int s=0,v=0;
    for(auto it:ar)
    {
        s+=it;
        if(it>t)
        return false;
        if (s > t) {
          v++;
          s=it;
        }
    }
    // if(s)
    if(s>0)
    v++;
    return v<=k;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int l=1e9,h=0;
    for (auto it : boards) {
        h += it;
        l=min(l,it);
    }
    int ans=0;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(ispossible(m,boards,k))
        {
            ans=m;
            h=m-1;
        }
        else l=m+1;
    }
    return ans;
}
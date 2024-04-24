class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=INT_MIN;
        int n=cardPoints.size(),s=0;
        vector<int> suf(n+1,0);
        for(int i=n-1;i>=0;i--)
            suf[n-i]=cardPoints[i]+suf[n-i-1];
        for(int i=0;i<=k;i++)
        {
            ans=max(ans,s+suf[k-i]);
            s+=cardPoints[i];
        }
        return ans;
    }
};
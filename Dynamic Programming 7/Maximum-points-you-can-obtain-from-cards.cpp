class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size(),s=0;
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++)
        {
        pre[i+1]=pre[i]+cardPoints[i];
        s+=cardPoints[i];
        }
        int ans=-1;
        for(int i=0;i<=k;i++)
        {
            int s1=pre[i];
            int s2=s-pre[n-k+i];
            ans=max(ans,s1+s2);
        }
        return ans;
    }
};
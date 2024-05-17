class Solution {
public:
vector<vector<int>> dp;
// int solve(vector<int>& ar,int i,int op,vector<int>& ml)
// {
//     if(op==ml.size())return 0;
//     if(dp[i][op]!=-1)return dp[i][op];
//     int fir=ar[i]*ml[op]+solve(ar,i+1,op+1,ml);
//     int las=ar[ar.size()-op+i-1]*ml[op]+solve(ar,i,op+1,ml);
//     return dp[i][op]=max(fir,las);
// }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size(),m=multipliers.size();
        dp.resize(n+1,vector<int>(multipliers.size()+1,0));
        // return solve(nums,0,0,multipliers);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int fir=nums[i]*multipliers[j]+dp[i+1][j+1],las=0;
                int x=n-1-j+i;
                if(x>=0&&x<n)
                las=nums[x]*multipliers[j]+dp[i][j+1];
                dp[i][j]=max(fir,las);
            }
        }
        return dp[0][0];
    }
};
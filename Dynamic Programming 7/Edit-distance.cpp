class Solution {
public:
int dp[501][501];
// int solve(string&a,string& b,int i,int j)
// {
//     if(i==a.size()||j==b.size())
//     {
//         if(i==a.size())return b.size()-j;
//         if(j==b.size())return a.size()-i;
//     }
//     if(dp[i][j]!=-1)return dp[i][j];
//     if(a[i]==b[j])
//     return dp[i][j]=solve(a,b,i+1,j+1);
//     return dp[i][j]=1+min({solve(a,b,i+1,j),solve(a,b,i,j+1),solve(a,b,i+1,j+1)});
// }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        memset(dp,0,sizeof(dp));
        // return solve(word1,word2,0,0);
        for(int i=0;i<=m;i++)
        dp[n][i]=m-i;
        for(int i=0;i<=n;i++)
        dp[i][m]=n-i;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(word1[i]==word2[j])
                dp[i][j]=dp[i+1][j+1];
                else
                dp[i][j]=1+min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
            }
        }
        return dp[0][0];
    }
};
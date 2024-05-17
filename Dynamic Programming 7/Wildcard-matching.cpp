class Solution {
public:
int dp[2001][2001];
// bool solve(string& s,string& p,int i,int j)
// {
//     if(j==p.size())
//         return i==s.size();
//     if(i==s.size()){
//         for(int q=j;q<p.size();q++)
//         if(p[q]!='*')return false;
//         return true;
//     }
//     if(dp[i][j]!=-1)return dp[i][j];
//     if(p[j]=='*')return dp[i][j]=solve(s,p,i+1,j)||solve(s,p,i+1,j+1)||solve(s,p,i,j+1);
//     if(p[j]=='?'||s[i]==p[j])return dp[i][j]=solve(s,p,i+1,j+1);
//     return dp[i][j]=false;
// }
    bool isMatch(string s, string p) {
        memset(dp,0,sizeof(dp));
        // return solve(s,p,0,0);
        int n=s.size(),m=p.size();
        dp[n][m]=1;
        for(int i=0;i<=m;i++)
        {
            int flg=0;
            for(int j=i;j<m;j++)
            if(p[j]!='*'){flg=1;break;}
            dp[n][i]=!flg;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(p[j]=='*')
                dp[i][j]=dp[i+1][j]||dp[i][j+1]||dp[i+1][j+1];
                else if(p[j]=='?'||p[j]==s[i])dp[i][j]=dp[i+1][j+1];
                else dp[i][j]=false;
            }
        }
        return dp[0][0];
    }
};
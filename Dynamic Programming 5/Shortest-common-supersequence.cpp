class Solution {
public:
int solve(string& a,string& b,int i,int j)
{
    if(i==a.size()||j==b.size())return 0;
    if(a[i]==b[j])
    return 1+solve(a,b,i+1,j+1);
    return max(solve(a,b,i+1,j),solve(a,b,i,j+1));
}
    string shortestCommonSupersequence(string str1, string str2) {
        // cout<<solve(str1,str2,0,0);
        int n=str1.size(),m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(str1[i]==str2[j])
                dp[i][j]=1+dp[i+1][j+1];
                else
                dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        int i = 0, j = 0;
        string lcs;
        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                lcs += str1[i];
                i++;
                j++;
            } else {
                if (dp[i][j + 1] > dp[i + 1][j])
                   j++;
                else
                   i++;
            }
        }
        int len=lcs.size();
        i=0,j=0;
        int k=0;
        string ans;
        while(k<len&&i<n&&j<m)
        {
            char ch=lcs[k];
            string d1,d2;
            while(i<n&&str1[i]!=ch)
                d1+=str1[i++];
            while(j<m&&str2[j]!=ch)
                d2+=str2[j++];
            d1+=d2;
            k++;i++;j++;
            ans+=d1;
            ans+=ch;
        }
        while(i<n)
        ans+=str1[i++];
        while(j<m)
        ans+=str2[j++];
        return ans;
    }
};
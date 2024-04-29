class Solution {
public:
    int *dp;
    int solve(string s, int i)
    {
        if (i == s.size())return 1;
        if (s[i] == '0')return 0;
        if (dp[i] != -1)return dp[i];
        int pickdouble = 0, picksingle = 0;
        if (i + 1 < s.size())
        {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            a *= 10;
            a += b;
            if (a <= 26)
                pickdouble = solve(s, i + 2);
        }
        picksingle = solve(s, i + 1);
        return dp[i] = pickdouble + picksingle;
    }
    int numDecodings(string s) {
        dp = new int[s.size() + 2];
        memset(dp, 0, (s.size() + 2)*sizeof(int));
        int n = s.size();
        dp[n] = 1, dp[n + 1] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != '0')
            {
                int pickdouble = 0, picksingle = 0;
                if (i + 1 < n)
                {
                    int a = s[i] - '0';
                    int b = s[i + 1] - '0';
                    a *= 10;
                    a += b;
                    if (a <= 26)
                        pickdouble = dp[i + 2];
                }
                picksingle = dp[i + 1];
                dp[i] = picksingle + pickdouble;
            }
        }
        return dp[0];
    }
};
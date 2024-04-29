class Solution
{
public:
    int*dp;
    const int mod = 1e9 + 7;
    int solve(int n)
    {
        if (n <= 0)return n == 0;
        if (dp[n] != -1)return dp[n] % mod;
        return dp[n] = ((solve(n - 1) % mod) + (1LL * (n - 1) * solve(n - 2) % mod) % mod) % mod;
    }
    int countFriendsPairings(int n)
    {
        dp = new int[n + 1];
        memset(dp, 0, (n + 1)*sizeof(int));
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] % mod;
            if (i - 2 >= 0)
                dp[i] += (1LL * (i - 1) * dp[i - 2] % mod) % mod;
        }
        return dp[n] % mod;
    }
};
class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<long long>> dp;
    long long solve(int n, int& k, int t)
    {
        if (n <= 0 || t <= 0)return n == 0 && t == 0;
        if (dp[n][t] != -1)return dp[n][t];
        long long ans = 0;
        for (int i = 1; i <= k; i++)
            ans = (ans + 1LL * solve(n - 1, k, t - i) % mod) % mod;
        return dp[n][t] = ans % mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int t = 1; t <= target; t++)
            {
                long long ans = 0;
                for (int w = 1; w <= k; w++)
                {
                    if (t - w >= 0)
                        ans = (ans + 1LL * dp[i - 1][t - w] % mod) % mod;
                }
                dp[i][t] = ans % mod;
            }
        }
        return dp[n][target] % mod;
    }
};
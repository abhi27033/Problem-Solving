class Solution {
public:
    int dp[50];
    int climbStair(int n)
    {
        if (n <= 0)return n == 0;
        if (dp[n] != -1)return dp[n];
        return dp[n] = climbStair(n - 2) + climbStair(n - 1);
    }
    int climbStairs(int n) {
        memset(dp, -1, 50 * sizeof(int));
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            if (i - 2 >= 0)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};
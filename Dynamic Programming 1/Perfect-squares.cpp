class Solution {
public:
    vector<vector<int>> dp;
    int solve(int s, int i)
    {
        if (s <= 0 || i * i > s)return s == 0 ? 0 : 100009;
        if (dp[s][i] != -1)return dp[s][i];
        int a = 1 + solve(s - i * i, i);
        int b = solve(s, i + 1);
        return dp[s][i] = min(a, b);
    }
    int numSquares(int n) {
        int f = sqrt(n);
        dp.resize(n + 1, vector<int>(f + 2, 100009));
        for (int i = 0; i <= f + 1; i++)
            dp[0][i] = 0;
        for (int s = 1; s <= n; s++)
        {
            for (int i = f; i >= 1; i--)
            {
                int a = INT_MAX;
                if ((s - i * i) >= 0)
                    a = 1 + dp[s - i * i][i];
                int b = dp[s][i + 1];
                dp[s][i] = min(a, b);
            }
        }
        return dp[n][1];
    }
};
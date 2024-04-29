class Solution {
public:
    long long *dp;
    long long solve(vector<vector<int>>& q, int i)
    {
        if (i >= q.size())return 0;
        if (dp[i] != -1LL)return dp[i];
        long long pick = q[i][0] + solve(q, i + q[i][1] + 1);
        long long npick = solve(q, i + 1);
        return dp[i] = max(pick, npick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        dp = new long long[questions.size() + 1];
        memset(dp, 0, (questions.size() + 1)*sizeof(long long));
        int n = questions.size();
        for (int i = n - 1; i >= 0; i--)
        {
            long long pick = questions[i][0] + (((i + questions[i][1] + 1) >= n) ? 0 : dp[i + questions[i][1] + 1]);
            long long npick = dp[i + 1];
            dp[i] = max(pick, npick);
        }
        return dp[0];
    }
};
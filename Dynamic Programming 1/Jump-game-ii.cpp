class Solution {
public:
    int* dp;
    int solve(vector<int>& ar, int idx)
    {
        if (idx >= ar.size() - 1)return idx == ar.size() - 1 ? 0 : 10009;
        if (dp[idx] != -1)return dp[idx];
        int ans = 10009;
        for (int i = idx + 1; i <= idx + ar[idx]; i++)
            ans = min(ans, 1 + solve(ar, i));
        return dp[idx] = ans;
    }
    int jump(vector<int>& nums) {
        dp = new int[nums.size()];
        memset(dp, -1, nums.size()*sizeof(int));
        int n = nums.size();
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int ans = 10009;
            for (int j = i + 1; j <= i + nums[i]; j++)
            {
                if (j >= n)break;
                ans = min(ans, 1 + dp[j]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};
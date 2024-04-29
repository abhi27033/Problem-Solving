class Solution {
public:
    int* dp;
    int solve(vector<int>& ar, int i, int n)
    {
        if (i >= n)return 0;
        if (dp[i] != -1)return dp[i];
        return dp[i] = max(ar[i] + solve(ar, i + 2, n), solve(ar, i + 1, n));
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1)return nums[0];
        dp = new int[nums.size() + 2];
        memset(dp, 0, (nums.size() + 2)*sizeof(int));
        for (int i = nums.size() - 2; i >= 0; i--)
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        int a = dp[0];
        memset(dp, 0, (nums.size() + 2)*sizeof(int));
        for (int i = nums.size() - 1; i >= 1; i--)
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        int b = dp[1];
        return max(a, b);
    }
};
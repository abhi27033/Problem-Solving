class Solution {
public:
    int* dp;
    int solve(vector<int>& ar, int i)
    {
        if (i >= ar.size())return 0;
        if (dp[i] != -1)return dp[i];
        return dp[i] = max(ar[i] + solve(ar, i + 2), solve(ar, i + 1));
    }
    int rob(vector<int>& nums) {
        dp = new int[nums.size() + 2];
        memset(dp, 0, (nums.size() + 2)*sizeof(int));
        for (int i = nums.size() - 1; i >= 0; i--)
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        return dp[0];
    }
};
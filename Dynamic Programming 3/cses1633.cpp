#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int mod = 1e9 + 7;
// int solve(int n)
// {
// 	if (n <= 0)return n == 0;
// 	if (dp[n] != -1)return dp[n] % mod;
// 	int ans = 0;
// 	for (int i = 1; i <= 6; i++)
// 		ans = (ans + solve(n - i) % mod) % mod;
// 	return dp[n] = ans % mod;
// }
int main() {
	int n;
	cin >> n;
	dp.resize(n + 1, 0);
	dp[0] = 1;
	// cout << solve(n) % mod;
	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		for (int j = 1; j <= 6; j++)
		{
			if (i - j >= 0)
				ans = (ans + dp[i - j] % mod) % mod;
		}
		dp[i] = ans % mod;
	}
	cout << dp[n] % mod;
	return 0;
}
 
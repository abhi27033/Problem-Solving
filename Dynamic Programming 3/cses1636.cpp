#include <bits/stdc++.h>
using namespace std;
// vector<vector<int>> dp;
int mod = 1e9 + 7;
// int solve(vector<int>& coins, int idx, int s)
// {
// 	if (s == 0)return 1;
// 	if (idx >= coins.size() || s < 0)return 0;
// 	if (dp[idx][s] != -1)return dp[idx][s] % mod;
// 	return dp[idx][s] = (solve(coins, idx, s - coins[idx]) % mod + solve(coins, idx + 1, s) % mod) % mod;
// }
int main() {
	int n, s;
	cin >> n >> s;
	vector<int> co(n);
	for (int i = 0; i < n; i++)
		cin >> co[i];
	// int dp[n + 1][s + 1];
	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int su = 0; su <= s; su++)
	// 	{
	// 		if (su == 0)
	// 			dp[i][su] = 1;
	// 		else
	// 			dp[i][su] = 0;
	// 	}
	// }
	// for (int i = n - 1; i >= 0; i--)
	// {
	// 	for (int su = 1; su <= s; su++)
	// 	{
	// 		int p = 0, np = 0;
	// 		if (su - co[i] >= 0)
	// 			p = dp[i][su - co[i]] % mod;
	// 		np = dp[i + 1][su] % mod;
	// 		dp[i][su] = (p + np) % mod;
	// 	}
	// }
	// int x = dp[0][s] % mod;
	// int x = solve(co, 0, s) % mod;
	vector<int> dp(s + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int su = co[i]; su <= s; su++) {
			dp[su] = (dp[su] + dp[su - co[i]]) % mod;
		}
	}
	int x = dp[s];
	cout << x << endl;
	return 0;
}

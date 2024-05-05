#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
// int solve(vector<int>& coins, int idx, int s)
// {
// 	if (s == 0)return 0;
// 	if (idx >= coins.size() || s < 0)return 1e7;
// 	if (dp[idx][s] != -1)return dp[idx][s];
// 	return dp[idx][s] = min(1 + solve(coins, idx, s - coins[idx]), solve(coins, idx + 1, s));
// }
int main() {
	int n, s;
	cin >> n >> s;
	vector<int> co(n);
	for (int i = 0; i < n; i++)
		cin >> co[i];
	dp.resize(n + 1, vector<int>(s + 1, 1e7));
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int su = 0; su <= s; su++)
		{
			int p = 1e7, np = 1e7;
			if (su - co[i] >= 0)
				p = 1 + dp[i][su - co[i]];
			np = dp[i + 1][su];
			dp[i][su] = min(p, np);
		}
	}
	int x = dp[0][s];
	// int x = solve(co, 0, s);
	if (x >= 1e7)
		cout << "-1";
	else
		cout << x;
	return 0;
}

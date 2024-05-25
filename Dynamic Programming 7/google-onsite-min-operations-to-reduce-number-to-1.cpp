#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
// int solve(int n)
// {
// 	if (n == 1)return 0;
// 	if (dp[n] != -1)return dp[n];
// 	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
// 	if (n > 1)
// 		op1 = 1 + solve(n - 1);
// 	if (n % 2 == 0)
// 		op2 = 1 + solve(n / 2);
// 	if (n % 3 == 0)
// 		op3 = 1 + solve(n / 3);
// 	return dp[n] = min({op1, op2, op3});
// }
int main() {
	int n;
	cin >> n;
	dp.resize(n + 1, 0);
	// cout << solve(n) << endl;
	for (int i = 2; i <= n; i++)
	{
		int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
		op1 = 1 + dp[i - 1];
		if (i % 2 == 0)
			op2 = 1 + dp[i / 2];
		if (i % 3 == 0)
			op3 = 1 + dp[i / 3];
		dp[i] = min({op1, op2, op3});
	}
	cout << dp[n];
	return 0;
}


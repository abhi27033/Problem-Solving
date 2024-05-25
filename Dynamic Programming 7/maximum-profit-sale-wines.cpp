#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
vector<vector<int>> ans;
// int solve(vector<int>& ar, int i, int j)
// {
// 	if (i > j)return 0;
// 	if (dp[i][j] != -1)return dp[i][j];
// 	int mul = ar.size() - (j - i);
// 	int p = ar[i] * mul + solve(ar, i + 1, j);
// 	int np = ar[j] * mul + solve(ar, i, j - 1);
// 	if (p >= np)
// 		ans[i][j] = 1;
// 	else
// 		ans[i][j] = 0;
// 	return dp[i][j] = max(p, np);
// }
int main() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	dp.resize(n + 1, vector<int>(n + 1, 0));
	ans.resize(n + 1, vector<int>(n + 1, -1));
	// int x = solve(ar, 0, n - 1) ;
	// int i = 0, j = n - 1;
	// while (i <= j)
	// {
	// 	if (ans[i][j] == 1)
	// 	{
	// 		cout << "beg ";
	// 		i++;
	// 	}
	// 	else
	// 	{
	// 		cout << "end ";
	// 		j--;
	// 	}
	// }
	// cout << endl;
	// cout << x << endl;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j <= n - 1; j++)
		{
			if (i > j)continue;
			int mul = n - (j - i);
			int p = ar[i] * mul + dp[i + 1][j];
			int np = ar[j] * mul + dp[i][j - 1];
			if (p >= np)
				ans[i][j] = 1;
			else
				ans[i][j] = 0;
			dp[i][j] = max(p, np);
		}
	}
	int x = dp[0][n - 1];
	int i = 0, j = n - 1;
	while (i <= j)
	{
		if (ans[i][j] == 1)
		{
			cout << "beg ";
			i++;
		}
		else
		{
			cout << "end ";
			j--;
		}
	}
	cout << endl;
	cout << x << endl;
	return 0;
}


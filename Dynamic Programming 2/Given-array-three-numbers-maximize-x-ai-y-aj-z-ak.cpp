#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int solve(vector<int>&ar, int i, int xyz, int&x, int&y, int&z)
{
	if (i == ar.size())return xyz == 3 ? 0 : -100009;
	if (xyz == 3)return 0;
	if (dp[i][xyz] != -100009)return dp[i][xyz];
	int pick = -100009, npick = -100009;
	if (xyz == 0)
		pick = ar[i] * x + solve(ar, i , xyz + 1, x, y, z);
	if (xyz == 1)
		pick = ar[i] * y + solve(ar, i , xyz + 1, x, y, z);
	if (xyz == 2)
		pick = ar[i] * z + solve(ar, i , xyz + 1, x, y, z);
	npick = solve(ar, i + 1, xyz, x, y, z);
	return dp[i][xyz] = max(pick, npick);
}
int main() {
	int n;
	cin >> n;
	int x, y, z;
	vector<int> ar(n);
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	cin >> x >> y >> z;
	dp.resize(n + 1, vector<int>(4, -100009));
	for (int i = 0; i <= n; i++)
		dp[i][3] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int xyz = 2; xyz >= 0; xyz--)
		{
			int pick = -100009, npick = -100009;
			if (xyz == 0)
				pick = ar[i] * x + dp[ i ][ xyz + 1];
			if (xyz == 1)
				pick = ar[i] * y + dp[ i ] [xyz + 1] ;
			if (xyz == 2)
				pick = ar[i] * z + dp[ i][ xyz + 1];
			npick = dp[ i + 1][ xyz];
			dp[i][xyz] = max(pick, npick);
		}
	}
	cout << dp[0][0] << endl;
	return 0;
}


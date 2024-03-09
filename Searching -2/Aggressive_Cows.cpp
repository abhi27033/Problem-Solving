#include <bits/stdc++.h>
using namespace std;
bool ispossible(int d, int c, vector<int>&st)
{
	int las = st[0], q = 1;
	for (int i = 1; i < st.size(); i++)
	{
		if (st[i] - las >= d)
		{
			q++;
			if (q == c)
				return true;
			las = st[i];
		}
	}
	return false;
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int n, c, ans = 1;
		cin >> n >> c;
		vector<int>st(n);
		for (int i = 0; i < n; i++)
			cin >> st[i];
		sort(st.begin(), st.end());
		int l = 1, h = st[n - 1] - st[0];
		while (l <= h)
		{
			int m = l + (h - l) / 2;
			if (ispossible(m, c, st))
			{
				ans = m;
				l = m + 1;
			}
			else
				h = m - 1;
		}
		cout << ans << endl;
	}
	return 0;
}
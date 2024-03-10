#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int n;
	cin >> n;
	vector<int> b(n);
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		mp[b[i]]++;
	}
	vector<int> fr;
	for (auto it : mp)
		fr.push_back(it.second);
	sort(fr.rbegin(), fr.rend());
	int a;
	cin >> a;
	int l = 1, h = fr[0], ans = -1;
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		if (fr.size() > a - 1 && fr[a - 1] >= m)
		{
			ans = m;
			l = m + 1;
		}
		else
			h = m - 1;
	}
	cout << ans << endl;
	return 0;
}
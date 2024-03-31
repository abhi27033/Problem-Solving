#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int n, flg = -1;
	cin >> n;
	vector<int> pre(n);
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	int mi = INT_MAX, ma = INT_MIN;
	for (int i = n - 1; i >= 0; i--)
	{
		if (pre[i] < mi || pre[i] > ma)
		{
			mi = min(mi, pre[i]);
			ma = max(ma, pre[i]);
		}
		else
		{
			cout << "FALSE\n";
			flg = 1;
			break;
		}
	}
	if (flg == -1)
		cout << "TRUE\n";
	return 0;
}
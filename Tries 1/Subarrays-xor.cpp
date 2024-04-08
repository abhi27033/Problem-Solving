#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	TrieNode* left, *right;
	long long count;
	TrieNode() {
		count = 0;
		left = NULL;
		right = NULL;
	}
};

TrieNode* root;

void insert(long long d) {
	TrieNode* t = root;
	for (int i = 63; i >= 0; i--) {
		long long mask = (d >> i) & 1LL;
		if (mask) {
			if (t->right == NULL)
				t->right = new TrieNode();
			t = t->right;
			t->count++;
		} else {
			if (t->left == NULL)
				t->left = new TrieNode();
			t = t->left;
			t->count++;
		}
	}
}

long long getc(TrieNode* y) {
	return y == NULL ? 0 : y->count;
}

long long solve(long long d, long long r) {
	TrieNode* t = root;
	long long ans = 0;
	for (int i = 63; i >= 0; i--) {
		long long m1 = (d >> i) & 1LL;
		long long m2 = (r >> i) & 1LL;
		if (m1) {
			if (m2) {
				ans += getc(t->right);
				if (t->left)
					t = t->left;
				else
					return ans;
			} else {
				if (t->right)
					t = t->right;
				else
					return ans;
			}
		} else {
			if (m2) {
				ans += getc(t->left);
				if (t->right)
					t = t->right;
				else
					return ans;
			} else {
				if (t->left)
					t = t->left;
				else
					return ans;
			}
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		root = new TrieNode();
		int n, k;
		cin >> n >> k;
		long long ans = 0;
		vector<long long> ar(n);
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		insert(0);
		long long t1 = 0;
		for (int i = 0; i < n; i++) {
			ans += solve(t1^ar[i], k);
			t1^=ar[i];
            insert(t1);
		}
		cout << ans << endl;
	}
}

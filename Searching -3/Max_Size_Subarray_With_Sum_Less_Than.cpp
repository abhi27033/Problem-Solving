#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
    int l = 0, r = INT_MAX, a, b, c, n;
    cin >> a >> b >> c >> n;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int n1 = m / a;
        n1 += (m / b);
        n1 += (m / c);
        if (n1 == n)
            return m;
        if (n1 < n)
            l = m + 1;
        else
            r = m - 1;
    }
    return 0;
}
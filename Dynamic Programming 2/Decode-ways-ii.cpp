class Solution {
public:
    long long dp[100009];
    const long long mod = 1e9 + 7;
    long long solve(string& s, int i) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];
        long long pickdouble = 0, picksingle = 0;
        if (i + 1 < s.size()) {
            if (s[i] == '*') {
                if (s[i + 1] == '*') {
                    pickdouble = (15LL * solve(s, i + 2) % mod) % mod;
                } else {
                    int b = s[i + 1] - '0';
                    if (b <= 6)
                        pickdouble = (2LL * solve(s, i + 2) % mod) % mod;
                    else
                        pickdouble = solve(s, i + 2) % mod;
                }
            } else {
                int a = s[i] - '0';
                if (s[i + 1] == '*') {
                    if (a <= 2) {
                        if (a == 1)
                            pickdouble = (9LL * solve(s, i + 2) % mod) % mod;
                        else
                            pickdouble = (6LL * solve(s, i + 2) % mod) % mod;
                    }
                } else {
                    int b = s[i + 1] - '0';
                    a *= 10;
                    a += b;
                    if (a <= 26) pickdouble = solve(s, i + 2) % mod;
                }
            }
        }
        if (s[i] == '*')
            picksingle = (9LL * solve(s, i + 1)) % mod;
        else
            picksingle = solve(s, i + 1) % mod;
        return dp[i] = (pickdouble % mod + picksingle % mod) % mod;
    }
    int numDecodings(string s) {
        for (int i = 0; i <= s.size(); i++) dp[i] = -1;
        return solve(s, 0);
    }
};

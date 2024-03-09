class Solution {
public:
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
    int solve(int n, int c, vector<int> &st) {
    
        // Write your code here
        sort(st.begin(), st.end());
		int l = 1, h = st[n - 1] - st[0],ans=1;
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
		return ans;
        
    }
};
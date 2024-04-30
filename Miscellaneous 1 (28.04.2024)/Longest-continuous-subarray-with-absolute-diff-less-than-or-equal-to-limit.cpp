class minseg {
public:
	vector<int> ar, seg;
	minseg(vector<int>& x, int n)
	{
		ar = x;
		seg.resize(4 * n);
		build(0, 0, n - 1);
	}
	void build(int idx, int l, int h)
	{
		if (l == h)
		{
			seg[idx] = ar[l];
			return;
		}
		int mid = (l + h ) / 2;
		build(2 * idx + 1, l, mid);
		build(2 * idx + 2, mid + 1, h);
		seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
	}
	int query(int idx, int l, int h, int ql, int qh)
	{
		//lies completely inside
		if (l >= ql && h <= qh)
			return seg[idx];
		//lies outside
		if (ql > h || qh < l)
			return INT_MAX;
		//overlaps
		int mid = (l + h ) / 2;
		int left = query(2 * idx + 1, l, mid, ql, qh);
		int right = query(2 * idx + 2, mid + 1, h, ql, qh);
		return min(left, right);
	}
};
class maxseg {
public:
	vector<int> ar, seg;
	maxseg(vector<int>& x, int n)
	{
		ar = x;
		seg.resize(4 * n);
		build(0, 0, n - 1);
	}
	void build(int idx, int l, int h)
	{
		if (l == h)
		{
			seg[idx] = ar[l];
			return;
		}
		int mid = (l + h ) / 2;
		build(2 * idx + 1, l, mid);
		build(2 * idx + 2, mid + 1, h);
		seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
	}
	int query(int idx, int l, int h, int ql, int qh)
	{
		//lies completely inside
		if (l >= ql && h <= qh)
			return seg[idx];
		//lies outside
		if (ql > h || qh < l)
			return INT_MIN;
		//overlaps
		int mid = (l + h ) / 2;
		int left = query(2 * idx + 1, l, mid, ql, qh);
		int right = query(2 * idx + 2, mid + 1, h, ql, qh);
		return max(left, right);
	}
};
class Solution {
public:
maxseg *ma;
minseg *mi;
int solve(int idx,vector<int>& nums,int lim)
{
    int n=nums.size();
    int l=idx,h=n-1;
    int ans=-1;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        int maxfromidx=ma->query(0,0,n-1,idx,m);
        int minfromidx=mi->query(0,0,n-1,idx,m);
        int adiff=maxfromidx-minfromidx;
        if(adiff<=lim)
        {
            ans=m;
            l=m+1;
        }
        else
        h=m-1;
    }
    return ans;
}
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        ma=new maxseg(nums,n);
        mi=new minseg(nums,n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=solve(i,nums,limit);
            int len=x-i+1;
            ans=max(ans,len);
        }
        return ans;
    }
};
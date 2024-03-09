class Solution {
public:
    int mySqrt(int x) {
        long long l=1,h=x,ans=0;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(1LL*m*m<=x)
            {
                ans=m;
                l=m+1;
            }
            else
            h=m-1;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            int a=0;
            while(st.size()&&st.top()<=heights[i]){
            st.pop();
            a++;
            }
            if(st.size())a++;
            st.push(heights[i]);
            ans[i]=a;
        }
        return ans;
    }
};
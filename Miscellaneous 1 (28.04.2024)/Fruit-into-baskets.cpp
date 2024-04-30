class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> s;
        int j=0,ans=0;
        for(int i=0;i<fruits.size();i++)
        {
            s[fruits[i]]++;
            while(s.size()>2&&j<=i)
            {
                s[fruits[j]]--;
                if(s[fruits[j]]==0)
                s.erase(fruits[j]);
                j++;
            }
            if(s.size()<=2)
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
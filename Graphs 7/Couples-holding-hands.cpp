class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int,int> pos;
        for(int i=0;i<row.size();i++)
        pos[row[i]]=i;
        int ans=0;
        for(int i=0;i<row.size()/2;i++)
        {
            int couple1=row[2*i];
            int couple2=couple1^1;
            if(couple2==row[2*i+1])continue;
            int position=pos[couple2];
            int temp=row[position];
            row[position]=row[2*i+1];
            row[2*i+1]=temp;
            pos[row[position]]=position;
            pos[row[2*i+1]]=2*i+1;
            ans++;
        }
        return ans;
    }
};
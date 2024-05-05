class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> s;
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<values.size();i++)
        {
        adj[equations[i][0]].push_back({equations[i][1],values[i]});
        adj[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        s.insert(equations[i][0]);
        s.insert(equations[i][1]);
        }
        vector<double> ans;
        for(auto it:queries)
        {
            string src=it[0];
            string dest=it[1];
            if(s.find(src)==s.end()||s.find(dest)==s.end())
            {
                ans.push_back(-1);
                continue;
            }
            unordered_set<string> vis;
            vis.insert(src);
            queue<pair<string,double>> q;
            q.push({src,1.0});
            int flg=-1;
            while(q.size())
            {
                int sz=q.size();
                while(sz--)
                {
                    string node=q.front().first;
                    double an=q.front().second;
                    if(node==dest)
                    {
                        ans.push_back(an);
                        flg=1;
                        break;
                    }
                    q.pop();
                    for(auto it:adj[node])
                    {
                        if(vis.find(it.first)==vis.end())
                        {
                            vis.insert(it.first);
                            q.push({it.first,an*it.second});
                        }
                    }
                }
                if(flg==1)break;
            }
            if(flg==-1)ans.push_back(-1);
        }
        return ans;
    }
};
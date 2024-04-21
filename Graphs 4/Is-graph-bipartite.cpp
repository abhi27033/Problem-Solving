class Solution {
public:
    bool solve(int node,vector<vector<int>>& adj,vector<int>& color)
    {
        if(color[node]==-1)
            color[node]=1;
        bool flg=true;   
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                flg&=solve(it,adj,color);
            }
            else if(color[it]!=1-color[node])
                flg=false;
        }
        return flg;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        if(!solve(i,graph,color))return false;
        return true;
    }
};
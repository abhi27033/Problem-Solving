class DSU{
    vector<int> par,rank;
    public:
    DSU(int n){
        par.resize(n,-1);
        rank.resize(n,1);
        for(int i=0;i<n;i++)
        par[i]=i;
    }
    int findpar(int node)
    {
        if(node==par[node])return node;
        return par[node]=findpar(par[node]);
    }
    bool unio(int u,int v)
    {
        int uu=findpar(u);
        int vv=findpar(v);
        if(uu==vv)return false;
        if(rank[uu]>rank[vv])
        par[vv]=par[uu];
        else if(rank[uu]<rank[vv])
        par[uu]=par[vv];
        else{
            par[uu]=par[vv];
            rank[vv]++;
        }
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> cost;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1=points[i][0];
                int x2=points[j][0];
                int y1=points[i][1];
                int y2=points[j][1];
                int dist=abs(x1-x2)+abs(y1-y2);
                cost.push_back({dist,i,j});
            }
        }
        sort(cost.begin(),cost.end());
        DSU f(n);
        int ans=0;
        for(auto it:cost)
        {
            int c=it[0];
            if(f.unio(it[1],it[2]))
                ans+=c;
        }
        return ans;
        
    }
};
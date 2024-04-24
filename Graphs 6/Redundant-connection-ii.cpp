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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int ma=INT_MIN;
        for(auto it:edges)
            ma=max({ma,it[0],it[1]});
        int a1=-1,a2=-1,n=edges.size();
        vector<int> ind(ma,-1);
        for(int i=0;i<n;i++)
        {
            if(ind[edges[i][1]-1]==-1)
                ind[edges[i][1]-1]=i;
            else
            {
                a1=i;
                a2=ind[edges[i][1]-1];
            }
        }
        if(a1==-1&&a2==-1)
        {
            DSU d(ma);
            for(int i=0;i<n;i++)
            {
            if(!d.unio(edges[i][0]-1,edges[i][1]-1))
                return edges[i];
            }
        }
        DSU d(ma);
        for(int i=0;i<n;i++)
        {
            if(i==a1)
                continue;
            if(!d.unio(edges[i][0]-1,edges[i][1]-1))
                return edges[a2];
        }
        return edges[a1];
    }
};
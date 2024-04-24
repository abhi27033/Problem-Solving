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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[](const vector<int>& a,const vector<int>& b){return a[0]>b[0];});
        DSU * al=new DSU(n);
        DSU * bo=new DSU(n);
        int a=0,b=0,ans=0;
        for(auto it:edges)
        {
            int typ=it[0];
            int u=it[1]-1;
            int v=it[2]-1;
            if(typ==3)
            {
            if(al->unio(u,v)||bo->unio(u,v))
            {
                al->unio(u,v);
                bo->unio(u,v);
                a++;
                b++;
            }
            else
            ans++;
            }
            else if(typ==1)
            {
                if(al->unio(u,v))
                a++;
                else
                ans++;
            }
            else{
                if(bo->unio(u,v))
                b++;
                else
                ans++;
            }
            // cout<<a<<" "<<b<<endl;
        }
        if(a==n-1&&b==n-1)
        return ans;
        return -1;
    }
};
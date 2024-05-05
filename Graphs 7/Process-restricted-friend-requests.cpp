class DSU{
    public:
  vector<int> rank;
    vector<int>  par;
    DSU(int n)
    {
        rank.resize(n,1);
        par.resize(n,1);
        for(int i=0;i<n;i++)
            par[i]=i;
    }
    int findpar(int u)
    {
        if(par[u]==u)return u;
        return par[u]=findpar(par[u]);
    }
    bool unio(int u,int v)
    {
        int uu=findpar(u);
        int vv=findpar(v);
        if(uu==vv)return false;
        if(rank[uu]<rank[vv])
            par[uu]=par[vv];
        else if(rank[vv]<rank[uu])
            par[vv]=par[uu];
        else
        {
            par[vv]=par[uu];
            rank[uu]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU d(n);
        vector<bool> ans;
        for(auto& it:requests)
        {
            ans.push_back(true);
            int u=d.findpar(it[0]);
            int v=d.findpar(it[1]);
            if(u!=v)
            {
            for(auto& itt:restrictions)
            {
                int uu=d.findpar(itt[0]),vv=d.findpar(itt[1]);
                if((uu==u&&vv==v)||(u==vv&&v==uu))
                {
                    ans[ans.size()-1]=false;
                    break;
                }
            }
            }
            if(ans[ans.size()-1]==true)
                d.unio(u,v);
        }
        return ans;
    }
};
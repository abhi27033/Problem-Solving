class DSU{
  vector<int> par,size;
  public:
  DSU(int n)
  {
    par.resize(n,0);
    size.resize(n,1);
    for(int i=0;i<n;i++)
    par[i]=i;
  }  
  int findpar(int n)
  {
    if(par[n]==n)return n;
    return par[n]=findpar(par[n]);
  }
  bool unite(int u,int v)
  {
    int uu=findpar(u);
    int vv=findpar(v);
    if(uu==vv)return false;
    if(size[uu]<=size[vv])
    {
        par[uu]=vv;
        size[vv]+=size[uu];
    }
    else
    {
        par[vv]=uu;
        size[uu]+=size[vv];
    }
    return true;
  }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU* a=new DSU(n);
        for(auto it:edges)
        {
            if(!a->unite(it[0]-1,it[1]-1))
            return it;
        }
        return {};
    }
};
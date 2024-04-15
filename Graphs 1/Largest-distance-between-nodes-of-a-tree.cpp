#include<bits/stdc++.h>
int dfs(int n,vector<vector<int>>& adj,vector<int>& vis,int& ma)
{
    int cm=0;
    vis[n]=1;
    for(auto it:adj[n])
    {
        if(vis[it]==-1)
        {
        int dis=dfs(it,adj,vis,ma);
        ma=max(ma,cm+dis);
        cm=max(cm,dis);
        }
    }
    ma=max(ma,cm);
    return cm+1;
}
int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<vector<int>> adj(n);
    int root;
    for(int i=0;i<n;i++)
    {
        if(A[i]==-1)
        root=i;
        else
        {
        adj[A[i]].push_back(i);
        adj[i].push_back(A[i]);
        }
    }
    vector<int> vis(n,-1);
    int ans=0;
    dfs(root,adj,vis,ans);
    return ans;
}
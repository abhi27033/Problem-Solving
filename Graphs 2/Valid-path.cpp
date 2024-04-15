#include <bits/stdc++.h>
bool check(int& x1,int& y1,vector<pair<int,int>>& cir,int& r)
{
    for(auto it:cir)
    {
        int x2=it.first;
        int y2=it.second;
        int x=abs(x1-x2);
        int y=abs(y1-y2);
        x*=x;
        y*=y;
        if(x+y<=r*r)
        return true;
    }
    return false;
}
bool solv(int i,int j,int dx[],int dy[],vector<pair<int,int>>& cir,vector<vector<int>>&vis,int&x,int&y,int& r)
{
    if(i<0||j<0||i>x||j>y||vis[i][j]==1||check(i,j,cir,r))
    return false;
    if(i==x&&j==y)
    return true;
    vis[i][j]=1;
    for(int dir=0;dir<8;dir++)
    {
        int newi=dx[dir]+i;
        int newj=dy[dir]+j;
        if(solv(newi,newj,dx,dy,cir,vis,x,y,r))
        return true;
    }
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    int dx[]={1,1,1,-1,-1,-1,0,0};
    int dy[]={1,0,-1,1,0,-1,1,-1};
    int x=A,y=B;
    int n=C,r=D;
    vector<pair<int,int>> cir;
    for(int i=0;i<n;i++)
    cir.push_back({E[i],F[i]});
    vector<vector<int>> vis(x+1,vector<int>(y+1,-1));
    return solv(0,0,dx,dy,cir,vis,x,y,r)?"YES":"NO";
}

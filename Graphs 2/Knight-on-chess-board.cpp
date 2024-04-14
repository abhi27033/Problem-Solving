#include<bits/stdc++.h>
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<int> dx={2,2,1,1,-1,-1,-2,-2};
    vector<int> dy={1,-1,2,-2,2,-2,1,-1};
    set<pair<int,int>> vis;
    queue<pair<int,int>> q;
    q.push({C,D});
    vis.insert({C,D});
    int l=0;
    while(q.size())
    {
        int s=q.size();
        while(s--)
        {
            int x=q.front().first;
            int y=q.front().second;
            if(x==E&&y==F)return l;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=1&&yy>=1&&xx<=A&&yy<=B)
                {
                    if(vis.find({xx,yy})==vis.end())
                    {
                        vis.insert({xx,yy});
                        q.push({xx,yy});
                    }
                }
            }
        }
        l++;
    }
    return -1;
}

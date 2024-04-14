class Solution {
public:
    bool check(int i,int j,int n,int m)
    {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        int fresh=0,l=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=1;
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(fresh==0)return 0;
        int xx=0;
        vector<pair<int,int>> dir;
        dir.push_back({0,1});dir.push_back({1,0});dir.push_back({0,-1});dir.push_back({-1,0});
        while(q.size())
        {
            int s=q.size();
            while(s--)
            {
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                for(auto d:dir)
                {
                    if(check(x+d.first,y+d.second,n,m)&&vis[x+d.first][y+d.second]==-1&&grid[x+d.first][y+d.second]==1)
                    {
                        grid[x+d.first][y+d.second]=2;
                        xx++;
                        vis[x+d.first][y+d.second]=1;
                        q.push({x+d.first,y+d.second});
                    }
                }
            }
            l++;
        }
        if(xx==fresh)return l-1;
        return -1;
    }
};
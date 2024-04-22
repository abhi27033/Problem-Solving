class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        int n=heights.size(),m=heights[0].size();
        set<pair<int,int>> vis;
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};
        while(pq.size())
        {
            int adiff=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            if(x==n-1&&y==m-1)return adiff;
            if(vis.find({x,y})!=vis.end())continue;
            vis.insert({x,y});
            for(int i=0;i<4;i++)
            {
                int newi=x+dx[i];
                int newj=y+dy[i];
                if(newi>=0&&newj>=0&&newi<n&&newj<m)
                {
                    int diff=abs(heights[x][y]-heights[newi][newj]);
                    diff=max(diff,adiff);
                    pq.push({diff,newi,newj});
                }
            }
        }
        return -1;
    }
};
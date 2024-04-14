class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                dis[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    vector<pair<int,int>> dir;
        dir.push_back({0,1});
        dir.push_back({1,0});
        dir.push_back({0,-1});
        dir.push_back({-1,0});
	    while(q.size())
	    {
	        int s=q.size();
	        while(s--)
	        {
	            int x=q.front().first;
	            int y=q.front().second;
	            q.pop();
	            for(auto it:dir)
	            {
	                int xx=x+it.first;
	                int yy=y+it.second;
	                if(xx>=0&&yy>=0&&xx<n&&yy<m&&dis[xx][yy]>1+dis[x][y])
	                {
	                    dis[xx][yy]=1+dis[x][y];
	                    q.push({xx,yy});
	                }
	            }
	        }
	    }
	    return dis;
	}
};
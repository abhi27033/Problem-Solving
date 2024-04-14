class Solution {
public:
    int n,m;
    bool check(int i,int j)
    {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    bool solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis)
    {
        if(!check(i,j)||vis[i][j]==1)return false;
        if(i==grid.size()-1&&j==grid[0].size()-1) return true;
        vis[i][j]=1;
        // cout<<grid[i][j]<<endl;
        if(grid[i][j]==1)
        {
            bool flg=false;
            if(check(i,j+1)&&(grid[i][j+1]==3||grid[i][j+1]==1||grid[i][j+1]==5))
                flg|=solve(grid,i,j+1,vis);
            if(check(i,j-1)&&(grid[i][j-1]==4||grid[i][j-1]==1||grid[i][j-1]==6))
                flg|=solve(grid,i,j-1,vis);
            return flg;
        }
        else if(grid[i][j]==2)
        {
            bool flg=false;
            if(check(i+1,j)&&(grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6))
                flg|=solve(grid,i+1,j,vis);
            if(check(i-1,j)&&(grid[i-1][j]==2||grid[i-1][j]==3||grid[i-1][j]==4))
                flg|=solve(grid,i-1,j,vis);
            return flg;
        }
        else if(grid[i][j]==3)
        {
            bool flg=false;
            if(check(i,j-1)&&(grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6))
                flg|=solve(grid,i,j-1,vis);
            if(check(i+1,j)&&(grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6))
                flg|=solve(grid,i+1,j,vis);
            return flg;
        }
        else if(grid[i][j]==4)
        {
            
            bool flg=false;
            if(check(i,j+1)&&(grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5))
                flg|=solve(grid,i,j+1,vis);
            if(check(i+1,j)&&(grid[i+1][j]==6||grid[i+1][j]==5||grid[i+1][j]==2))
                flg|=solve(grid,i+1,j,vis);
            return flg;
        }
        else if(grid[i][j]==5)
        {
            bool flg=false;
            if(check(i-1,j)&&(grid[i-1][j]==4||grid[i-1][j]==3||grid[i-1][j]==2))
                flg|=solve(grid,i-1,j,vis);
            if(check(i,j-1)&&(grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6))
                flg|=solve(grid,i,j-1,vis);
            return flg;
        }
        else if(grid[i][j]==6)
        {
            bool flg=false;
            if(check(i-1,j)&&(grid[i-1][j]==4||grid[i-1][j]==3||grid[i-1][j]==2))
                flg|=solve(grid,i-1,j,vis);
            if(check(i,j+1)&&(grid[i][j+1]==5||grid[i][j+1]==3||grid[i][j+1]==1))
                flg|=solve(grid,i,j+1,vis);
            return flg;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(grid,0,0,vis);
    }
};
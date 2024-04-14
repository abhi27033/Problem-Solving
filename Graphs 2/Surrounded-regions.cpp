class Solution {
public:
    vector<pair<int,int>> dir;
    void dfs(vector<vector<char>>& board,int i,int j,vector<vector<int>>& vis,char ch)
    {
        int n=board.size(),m=board[0].size();
        if(i<0||j<0||i>=n||j>=m||vis[i][j]==1||board[i][j]=='X')return;
        vis[i][j]=1;
        board[i][j]=ch;
        for(auto it:dir)
            dfs(board,i+it.first,j+it.second,vis,ch);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        dir.push_back({0,1});dir.push_back({1,0});dir.push_back({0,-1});dir.push_back({-1,0});
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0||j==0||i==n-1||j==m-1)&&board[i][j]=='O')
                    dfs(board,i,j,vis,'&');
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='&')
                    board[i][j]='O';
            }
        }
    }
};
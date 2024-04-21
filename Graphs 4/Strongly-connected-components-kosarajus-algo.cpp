class Solution
{
	public:
	
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,stack<int>& s)
	{
	    if(vis[node]==1)
	    return;
	    vis[node]=1;
	    for(auto it:adj[node])
	    dfs(it,adj,vis,s);
	    s.push(node);
	}
	void ddfs(int node,vector<vector<int>>& rev,vector<int>& vis)
	{
	    if(vis[node]==1)return;
	    vis[node]=1;
	    for(auto it:rev[node])
	    ddfs(it,rev,vis);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> s;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
        if(vis[i]==0)
        dfs(i,adj,vis,s);
        }
        vector<vector<int>> rev(V);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            rev[it].push_back(i);
        }
        for(int i=0;i<V;i++)
        vis[i]=0;
        int ans=0;
        while(s.size())
        {
            int it=s.top();
            s.pop();
            if(vis[it]==0)
            {
                ddfs(it,rev,vis);
                ans++;
            }
        }
        return ans;
    }
};
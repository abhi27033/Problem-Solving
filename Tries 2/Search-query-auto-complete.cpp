class AutoCompleteSystem {
public:
struct TrieNode
{
    unordered_map<string,int> pq;
    TrieNode* child[27];
    TrieNode(){
        memset(child,NULL,sizeof(child));
    }
};
int mask(char c)
{
    if(c==' ')
    return 0;
    return c-'a'+1;
}
void store(string s,int p)
{
    TrieNode* t=r;
    for(auto it:s)
    {
        if(t->child[mask(it)]==NULL) t->child[mask(it)]=new TrieNode();
        t=t->child[mask(it)];
        if(t->pq.find(s)==t->pq.end())
        {
            if(t->pq.size()<3)
                t->pq[s]=p;
            else
            {
                //find minimum and remove it
                int mi=INT_MAX;
                string dummy;
                for(auto it:t->pq)
                {
                    if(mi>it.second)
                    {
                        mi=it.second;
                        dummy=it.first;
                    }
                }
                for(auto it:t->pq)
                {
                    if(mi==it.second)
                        dummy=max(dummy,it.first);
                }
                if(mi<p||mi==p&&s<dummy){
                    t->pq.erase(dummy);
                    t->pq[s]=p;
                }
            }
        }
        else
            t->pq[s]=max(t->pq[s],p);
    }
}
    string x;
    TrieNode* r;
    unordered_map<string,int> mp;
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        // write code for constructor
        r=new TrieNode();
       vector<pair<string,int>> p;
       for(int i=0;i<sentences.size();i++)
          p.push_back({sentences[i],times[i]});
          sort(p.begin(),p.end());
        x="";
        mp.clear();
        for(auto it:p)
        {
            store(it.first,it.second);
            mp[it.first]=it.second;
        }
    }
    vector<string> solve(string s)
    {
        // cout<<s<<endl;
        TrieNode* t=r;
        for(auto it:s)
        {
            if(t->child[mask(it)]==NULL)
            return {};
            t=t->child[mask(it)];
        }
        vector<string> ans;
        vector<pair<int,string>> tem;
        for(auto it:t->pq)
        tem.push_back({it.second,it.first});
        sort(tem.begin(),tem.end(),[](auto a,auto b){
            if(a.first>b.first)
            return true;
            else if(a.first==b.first&&a.second<b.second)
            return true;
            else
            return false;
        });
        for(auto it:tem)
        ans.push_back(it.second);
        return ans;
    }
    vector<string> input(char c) {
        // write code to return the top 3 suggestions when the current character in the stream is c
        // c == '#' means , the current query is complete and you may save the entire query into
        // historical data
        if(c=='#')
        {
        //store x in trie
        mp[x]++;
        store(x,mp[x]); 
        x="";
        return {};
        }
        x+=c;
        vector<string> ans=solve(x);
        return ans;
    }
};

/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

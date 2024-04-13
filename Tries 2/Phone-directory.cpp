
class Solution{
public:
struct TrieNode{
  TrieNode* child[26];
  vector<int> ind;
  TrieNode()
  {
      memset(child,NULL,sizeof(child));
  }
};
TrieNode* r;
void insert(string x,int idx)
{
    TrieNode*t=r;
    for(auto it:x)
    {
        if(t->child[it-'a']==NULL)
        t->child[it-'a']=new TrieNode();
        t=t->child[it-'a'];
        t->ind.push_back(idx);
    }
}
vector<string> solve(string s,string *ar)
{
    TrieNode* t=r;
    vector<string> ans;
    for(auto it:s)
    {
        if(t->child[it-'a']==NULL)
        return ans;
        t=t->child[it-'a'];
    }
    for(auto it:t->ind)
    ans.push_back(ar[it]);
    return ans;
}
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        r=new TrieNode();
        // sort(contact,contact+n);
        unordered_set<string> st;
        for(int i=0;i<n;i++)
        {
        if(st.find(contact[i])==st.end())
        insert(contact[i],i);
        st.insert(contact[i]);
        }
        vector<vector<string>> ans;
        string sub;
        for(auto it:s)
        {
            sub+=it;
            vector<string> a=solve(sub,contact);
            sort(a.begin(),a.end());
            if(a.size()==0)
            ans.push_back({"0"});
            else
            ans.push_back(a);
        }
        return ans;
    }
};
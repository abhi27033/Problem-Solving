class Solution {
public:
    struct TrieNode{
      int isend,count;
      TrieNode* child[26];
        TrieNode()
        {
            isend=false;
            count=0;
            memset(child,NULL,sizeof(child));
        }
    };
    TrieNode* r;
    void insert(string& w)
    {
        TrieNode* t=r;
        for(int i=0;i<w.size();i++)
        {
            if(t->child[w[i]-'a'])
                t=t->child[w[i]-'a'];
            else
            {
                t->child[w[i]-'a']=new TrieNode();
                t=t->child[w[i]-'a'];
            }
            t->count++;
        }
        t->isend=true;
    }
    int solve(string& w)
    {
        TrieNode* t=r;
        int ans=0;
        for(int i=0;i<w.size();i++)
        {
            if(t->child[w[i]-'a'])
                t=t->child[w[i]-'a'];
           ans+=t->count;
        }
       return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        r=new TrieNode();
        for(auto it:words)
            insert(it);
        vector<int> ans;
        for(auto it:words)
        {
            int c=solve(it);
            ans.push_back(c);
        }
        return ans;
    }
};
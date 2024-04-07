class Solution {
public:
    struct TrieNode{
        bool isend;
        TrieNode* child[26];
        TrieNode()
        {
            isend=false;
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
        }
        t->isend=true;
    }
    string solve(string& w)
    {
        TrieNode* t=r;
        string q; 
        for(int i=0;i<w.size();i++)
        {
             q+=w[i];
            if(t->child[w[i]-'a'])
                t=t->child[w[i]-'a'];
            else
            return t->isend?q:w;
            if(t->isend)
                    return q;
        }
        return t->isend?q:w;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        r=new TrieNode();
        for(auto it:dictionary)
            insert(it);
        sentence+=" ";
        string ans;
        for(int i=0;i<sentence.size();i++)
        {
            string word;
            while(sentence[i]!=' ')
                word+=sentence[i++];
            ans+=solve(word);
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};
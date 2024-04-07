class Trie {
public:
    struct TrieNode{
      bool isend;
      vector<TrieNode*> child;
      TrieNode()
      {
          isend=false;
          child.resize(26,NULL);
      }
    };
    TrieNode* x;
    Trie() {
        x=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* t=x;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            if(t->child[ch-'a'])
            t=t->child[ch-'a'];
            else
            {
                t->child[ch-'a']=new TrieNode();
                t=t->child[ch-'a'];
            }
        }
        t->isend=true;
    }
    
    bool search(string word) {
        TrieNode* t=x;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            if(t->child[ch-'a'])
            t=t->child[ch-'a'];
            else
            return false;
        }
        return t->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode* t=x;
        for(int i=0;i<prefix.size();i++)
        {
            char ch=prefix[i];
            if(t->child[ch-'a'])
            t=t->child[ch-'a'];
            else
            return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
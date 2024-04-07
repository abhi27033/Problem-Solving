class Solution {
public:
    struct TrieNode {
	bool isend;
    int last;
	TrieNode* child[26];
	int word[5009];
	TrieNode() {
		isend = false;
        last=0;
		memset(child, NULL,sizeof(child));
	}
};
    TrieNode* r;
    void insert(string w,int idx)
    {
        TrieNode* t=r;
        reverse(w.begin(),w.end());
        for(int i=0;i<w.size();i++)
        {
            if(t->child[w[i]-'a'])
            {
                t=t->child[w[i]-'a'];
                t->word[t->last]=idx;
                t->last++;
            }
            else
            {
                t->child[w[i]-'a']=new TrieNode();
                t=t->child[w[i]-'a'];
                t->word[t->last]=idx;
                t->last++;
            }
        }
        t->isend=true;
    }
    int solve(vector<string>& words,string w)
    {
        TrieNode* t=r;
        for(int i=0;i<w.size();i++)
        {
            if(t->child[w[i]-'a'])
                t=t->child[w[i]-'a'];
            else
                break;
        }
        
        int minlen=INT_MAX,minidx=-1;
        for(int i=0;i<t->last;i++)
        {
            int it=t->word[i];
            if(words[it].size()<minlen)
            {
                minlen=words[it].size();
                minidx=it;
            }
        }
        return minidx;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        r=new TrieNode();
        for(int i=0;i<wordsContainer.size();i++)
        {
            r->word[r->last]=i;
            r->last++;
            insert(wordsContainer[i],i);
        }
        vector<int> ans;
        for(auto it:wordsQuery)
        {
            string fin=it;
            reverse(fin.begin(),fin.end());
            ans.push_back(solve(wordsContainer,fin));
        }
        return ans;
    }
};
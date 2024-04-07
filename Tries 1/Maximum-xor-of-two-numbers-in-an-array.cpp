class Solution {
public:
    struct TrieNode{
      TrieNode* child[2];
        TrieNode()
        {
            memset(child,NULL,sizeof(child));
        }
    };
    void insert(int d,TrieNode*& r)
    {
        TrieNode* t=r;
        for(int i=31;i>=0;i--)
        {
            int bit=(d>>i)&1;
            if(t->child[bit])
                t=t->child[bit];
            else
            {
                t->child[bit]=new TrieNode();
                t=t->child[bit];
            }
        }
    }
    int getmax(int d,TrieNode*& r)
    {
        TrieNode* t=r;
        int x=0;
        for(int i=31;i>=0;i--)
        {
            int bit=((d>>i)&1);
            if(t->child[1-bit])
            {
                x+=(1<<i);
                t=t->child[1-bit];
            }
            else
               t=t->child[bit];
        }
        return x;
    }
    int findMaximumXOR(vector<int>& nums) {
      TrieNode* r=new TrieNode();
        insert(nums[0],r);
        int ans=0;
        for(int i=1;i<nums.size();i++)
        {
            int m=getmax(nums[i],r);
            ans=max(ans,m);
            insert(nums[i],r);
        }
        return ans;
    }
};
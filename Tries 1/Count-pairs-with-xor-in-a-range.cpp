class Solution {
public:
struct TrieNode{
TrieNode* left,*right;
int count;
TrieNode()
{
    count=0;
    left=NULL;
    right=NULL;
}
};
TrieNode* root;
void insert(int d)
{
    TrieNode* t=root;
    for(int i=15;i>=0;i--)
    {
        int mask=(d>>i)&1;
        if(mask)
        {
            if(t->right==NULL)
            t->right=new TrieNode();
            t=t->right;
            t->count++;
        }
        else
        {
            if(t->left==NULL)
            t->left=new TrieNode();
            t=t->left;
            t->count++;
        }
    }
}
int getc(TrieNode* y)
{
    return y==NULL?0:y->count;
}
int solve(int d,int r)
{
    TrieNode* t=root;
    int ans=0;
    for(int i=15;i>=0;i--)
    {
        int m1=(d>>i)&1;
        int m2=(r>>i)&1;
        if(m1)
        {
            if(m2)
            {
                //we have data ith bit set and have set r ith bit cant say go to 
                //if we take 1 all are small-->1^x==1
                ans+=getc(t->right);
                if(t->left)
                t=t->left;
                else
                return ans;
            }
            else
            {
                //we have data ith bit set we have unset r ith bit--->1^x==0
                //if we take 0 we cant get any thing greter occurs
                //we can take 1
                if(t->right) 
                t=t->right;
                else
                return ans;
            }
        }
        else
        {
            if(m2)
            {
                //we have data ith bit unset and set r ith bit--->0^x==1
                //if we take 0 all are less and if 1 the equal go forward
                ans+=getc(t->left);
                if(t->right) 
                t=t->right;
                else
                return ans;
            }
            else
            {
                // we have data ith bit unset and unset r ith bit--> 0^x==0
                //if we take 0 then equal go forward if 1 then increased no need
                if(t->left)
                t=t->left;
                else
                return ans;
            }
        }
    }
    return ans+t->count;
}

    int countPairs(vector<int>& nums, int low, int high) {
        root=new TrieNode();
        int ans=0;
        insert(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            ans+=solve(nums[i],high);
            ans-=solve(nums[i],low-1);
            // cout<<i<<" "<<ans<<endl;
            insert(nums[i]);
        }
        return ans;
    }
};
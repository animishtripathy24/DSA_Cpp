//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  private:
    TNode* inorderToBST(vector<int>&nums,int start,int end)
    {
        if(start>end) 
            return NULL;

        int mid=(start+end)>>1;
        if((start+end) & 1)
        {
            mid++;
        }
        TNode* root=new TNode(nums[mid]);
        root->left=inorderToBST(nums,start,mid-1);
        root->right=inorderToBST(nums,mid+1,end);
        return root;
    }
  public:
    TNode* sortedListToBST(LNode *head) {
        LNode* curr=head;
        vector<int>ans;
        while(curr != NULL)
        {
            ans.push_back(curr->data);
            curr=curr->next;
        }
         return inorderToBST(ans,0,ans.size()-1);
    }
};

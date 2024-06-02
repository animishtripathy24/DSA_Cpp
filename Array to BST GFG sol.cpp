struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
private:
    Node* solve(vector<int>nums,int start,int end)
    {
        //base case
        if(start > end)
        {
            return NULL;
        }
        int mid=(start+end)>>1;
        Node* root=new Node(nums[mid]);
        root->left=solve(nums,start,mid-1);
        root->right=solve(nums,mid+1,end);
        return root;
    }
    void preOrder(Node* root,vector<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }
        ans.push_back(root->data);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
        return;
    }
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        Node* root=solve(nums,0,nums.size()-1);
        vector<int>ans;
        preOrder(root,ans);
        return ans;
    }
};

class Solution{
    private:
    Node* inorderToBST(vector<int>&arr,int low,int high)
    {
        if(low > high)
        {
            return NULL;
        }
        int mid = low+((high-low)>>1);
        Node* root = new Node(arr[mid]);
        root->left = inorderToBST(arr,low,mid-1);
        root->right = inorderToBST(arr,mid+1,high);
        return root;
    }
    void findInorder(Node* root,vector<int>&inorder)
    {
        if(root == NULL)
        {
            return;
        }
        findInorder(root->left,inorder);
        inorder.push_back(root->data);
        findInorder(root->right,inorder);
    }
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
        vector<int>inorder;
        findInorder(root,inorder);
        return inorderToBST(inorder,0,inorder.size()-1);
    }
};

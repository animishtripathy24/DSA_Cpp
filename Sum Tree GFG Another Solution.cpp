class Solution {
  private:
    int solve(Node* root)
    {
        if( root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return root->data;
        }
        int left = solve(root->left);
        if(left == -1)
        {
            return -1;
        }
        int right = solve(root->right);
        if(right == -1)
        {
            return -1;
        }
        int sum = left + right;
        if(sum != root->data)
        {
            return -1;
        }
        return root->data + left + right;
        
    }
  public:
    bool isSumTree(Node* root) {
        if(root == NULL)
        {
            return 0;
        }
        if(solve(root) == -1)
        {
            return 0;
        }
        return 1;
    }
};

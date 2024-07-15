class Solution {
  private:
    int solve(Node* &root)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(!root->left && !root->right)
        {
            int number = root->data;
            root->data = 0;
            return number;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        int res = left+ right + root->data;
        root->data = left + right;
        return res;
    }
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        solve(node);
    }
};

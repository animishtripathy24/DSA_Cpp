class Solution{
private:
    bool valid(Node* &root, long int minValue, long int maxValue)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->data <= minValue || root->data >= maxValue)
        {
            return false;
        }
        return valid(root->left, minValue, root->data) && valid(root->right, root->data, maxValue);
    }

    int getCount(Node* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + getCount(root->left) + getCount(root->right);
    }
    void solve(Node* root, int &maxi)
    {
        if (root == NULL)
        {
            return;
        }
        if (valid(root, LONG_MIN, LONG_MAX))
        {
            int count = getCount(root);
            maxi = max(maxi, count);
        }
        solve(root->left, maxi);
        solve(root->right, maxi);
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        int maxi = 0;
        solve(root, maxi);
        return maxi;
    }
};

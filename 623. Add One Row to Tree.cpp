class Solution {
private:
    void solve(TreeNode* root, int val, int depth, int currentDepth) 
    {
        if (root == NULL) 
        {
            return;
        }
        if (currentDepth == depth - 1) 
        {
            TreeNode* leftSubtree = root->left;
            TreeNode* rightSubtree = root->right;
            
            TreeNode* newLeftNode = new TreeNode(val);
            TreeNode* newRightNode = new TreeNode(val);
            
            root->left = newLeftNode;
            root->right = newRightNode;
            
            newLeftNode->left = leftSubtree;
            newRightNode->right = rightSubtree;
        } 
        else 
        {
            solve(root->left, val, depth, currentDepth + 1);
            solve(root->right, val, depth, currentDepth + 1);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) 
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        TreeNode* curr=root;
        int count=1;
        solve(root,val,depth,count);
        return curr;
    }
};

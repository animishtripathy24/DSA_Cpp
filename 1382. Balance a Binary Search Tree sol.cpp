/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* inorderToBST(vector<int>&inorder,int low,int high)
    {
        //base case
        if(low > high)
        {
            return NULL;
        }
        //now we will find the mid of the vector
        int mid= low+((high-low)>>1);
        TreeNode* root= new TreeNode(inorder[mid]);
        root->left=inorderToBST(inorder,low,mid-1);
        root->right=inorderToBST(inorder,mid+1,high);

        return root;
    }
    void findInorder(TreeNode* root,vector<int>&inorder)
    {
        //base case
        if(root == NULL)
        {
            return;
        }
        findInorder(root->left,inorder);
        inorder.push_back(root->val);
        findInorder(root->right,inorder);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        //at first we have to find the inorder of the BST
        vector<int>inorder;
        findInorder(root,inorder);
        return inorderToBST(inorder,0,inorder.size()-1);
    }
};

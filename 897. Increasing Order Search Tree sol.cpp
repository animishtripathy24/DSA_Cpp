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
    void getInorder(TreeNode* root,vector<int>&inorder)
    {
        if(!root) return;
        getInorder(root->left,inorder);
        inorder.push_back(root->val);
        getInorder(root->right,inorder);
        return;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>inorder;
        getInorder(root,inorder);
        TreeNode* rootNew=new TreeNode(inorder[0]);
        TreeNode* curr=rootNew;
        for(int i=1;i<inorder.size();i++)
        {
            TreeNode* newNode = new TreeNode(inorder[i]);
            curr->right=newNode;
            curr=newNode;
        }
        return rootNew;
    }
};

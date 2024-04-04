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
    void inorder(TreeNode* root,int &mini,TreeNode* &prev)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,mini,prev);
        if(prev)
        {
            mini=min(mini,abs(prev->val-root->val));
        }
        prev=root;
        inorder(root->right,mini,prev);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int mini=INT_MAX;
        TreeNode* prev=NULL;
        inorder(root,mini,prev);
        return mini;
        
    }
};

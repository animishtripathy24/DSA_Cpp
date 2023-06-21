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
public:
    int dfsHeight(TreeNode* root)
    {
        //base case...jab bhi root null ho jaye return 0 kar dena hai
        if(root == NULL)
        {
            return 0;
        }

        int lh=dfsHeight(root->left);
        if(lh==-1)
        {
            return -1;
        }
        int rh=dfsHeight(root->right);
        if(rh==-1)
        {
            return -1;
        }
        if(abs(rh-lh)>1)
        {
            return -1;
        }
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(dfsHeight(root) != -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
};

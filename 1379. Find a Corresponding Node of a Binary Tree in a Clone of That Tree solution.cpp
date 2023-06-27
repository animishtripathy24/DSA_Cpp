/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
TreeNode* curr;
private:
    void solve(TreeNode* cloned,TreeNode* target)
    {
        if(cloned==NULL)
        {
            return;
        }
        if(cloned->val == target->val)
        {
            curr=cloned;
        }
        solve(cloned->left,target);
        solve(cloned->right,target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if((cloned==NULL)|| (cloned == target && cloned->left == NULL && cloned->right==NULL))
    {
        return cloned;
    }
    solve(cloned,target);
    return curr;
        
    }
};

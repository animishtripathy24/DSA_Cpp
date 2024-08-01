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
    void solve(TreeNode* root,int steps,bool goLeft,int &maxPath)
    {
        if(root == NULL)
        {
            return;
        }
        maxPath = max(maxPath,steps);

        if(goLeft == true)
        {
            solve(root->left,steps+1,false,maxPath);
            solve(root->right,1,true,maxPath);
        }
        else
        {
            solve(root->right,steps+1,true,maxPath);
            solve(root->left,1,false,maxPath);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int maxPath = 0;
        solve(root,0,1,maxPath);
        solve(root,0,0,maxPath);
        return maxPath;
    }
};

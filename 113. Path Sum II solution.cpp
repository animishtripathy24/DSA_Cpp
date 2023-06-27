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
    void solve(TreeNode* root,int targetSum,vector<int>&path,vector<vector<int>>&ans)
    {
        if(!root)
        {
            return;
        }
        if(root->left == NULL && root->right==NULL)
        {
            path.push_back(root->val);
            if(accumulate(path.begin(),path.end(),0)==targetSum)
            {
                ans.push_back(path);
            }
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        solve(root->left,targetSum,path,ans);
        solve(root->right,targetSum,path,ans);
        path.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root==NULL)
        {
            return {};
        }

        vector<int>path;
        vector<vector<int>>ans;
        solve(root,targetSum,path,ans);
        return ans;
        
    }
};

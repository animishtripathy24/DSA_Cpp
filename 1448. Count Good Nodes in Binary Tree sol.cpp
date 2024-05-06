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
    void solve(TreeNode* root,vector<int>&ans,int& count)
    {
        if(root == NULL)
        {
            return;
        }
        int x=root->val;
        ans.push_back(x);
        bool check=false;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]>x)
            {
                check=true;
            }
        }
        if(!check)
        {
            count++;
        }
        solve(root->left,ans,count);
        solve(root->right,ans,count);
        ans.pop_back();
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        vector<int>ans;
        int count=0;
        solve(root,ans,count);
        return count;
    }
};

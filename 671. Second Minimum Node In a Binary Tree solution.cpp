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
    void solve(TreeNode* root,vector<int>&v)
    {
        if(root==NULL)
        {
            return;
        }
        v.push_back(root->val);
        solve(root->left,v);
        solve(root->right,v);
        return;
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL)
        {
            return -1;
        }
        vector<int>v;
        solve(root,v);
        set<int>s;
        for(auto &value:v)
        {
            s.insert(value);
        }
        if(s.size()<=1)
        {
            return -1;
        }
        return *(++s.begin());
        
    }
};

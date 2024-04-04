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
        if(!root)
        {
            return;
        }
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    vector<int> merge(vector<int>&v1,vector<int>&v2)
    {
        vector<int>temp;
        int i=0;
        int j=0;
        while(i<v1.size() && j<v2.size())
        {
            if(v1[i]<=v2[j])
            {
                temp.push_back(v1[i++]);
            }
            else
            {
                temp.push_back(v2[j++]);
            }
        }
        while(i<v1.size())
        {
            temp.push_back(v1[i++]);
        }
        while(j<v2.size())
        {
            temp.push_back(v2[j++]);
        }
        return temp;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
        solve(root1,v1);
        solve(root2,v2);
        return merge(v1,v2);
    }
};

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
    void solve(TreeNode* root,string &str,vector<string>&v)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            str.push_back(root->val+'0');
            v.push_back(str);
            str.pop_back();
            return;
        }
        str.push_back(root->val+'0');
        solve(root->left,str,v);
        solve(root->right,str,v);
        str.pop_back();
        return;
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        vector<string>v;
        string str;
        solve(root,str,v);
        long long sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=stoi(v[i]);
        }
        return (int)sum;
    }
};

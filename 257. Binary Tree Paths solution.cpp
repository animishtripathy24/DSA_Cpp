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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        vector<string>ans;
        vector<int>path;
        solve(root,path,ans);
        return ans;
        
    }

    void solve(TreeNode* root,vector<int>&path,vector<string>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left == NULL && root->right==NULL)
        {
            path.push_back(root->val);
            ans.push_back(convert(path));
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        solve(root->left,path,ans);
        solve(root->right,path,ans);
        path.pop_back();
        return;

    }
    string convert(vector<int>&path)
    {
        string temp;
        for(int i=0;i<path.size()-1;i++)
        {
            temp+=to_string(path[i]);
            temp.push_back('-');
            temp.push_back('>');
        }
        temp+=to_string(path[path.size()-1]);
        return temp;
    }
};

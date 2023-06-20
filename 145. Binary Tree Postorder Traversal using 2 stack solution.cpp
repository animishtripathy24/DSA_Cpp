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
    vector<int> postorderTraversal(TreeNode* root) {

        if(root == NULL)
        {
            return {};
        }
        vector<int>v;
        stack<TreeNode*>s1,s2;
        s1.push(root);

        while(!s1.empty())
        {
            root=s1.top();
            s1.pop();
            s2.push(root);
            if(root->left)
            {
                s1.push(root->left);
            }
            if(root->right)
            {
                s1.push(root->right);
            }
        }

        while(!s2.empty())
        {
            TreeNode* curr=s2.top();
            s2.pop();
            v.push_back(curr->val);
        }

        return v;
        
    }
};

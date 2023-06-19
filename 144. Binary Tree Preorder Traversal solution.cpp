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
    vector<int> preorderTraversal(TreeNode* root) {
        //sabse pehle we have to check whether root is not NULL
        if(root == NULL)
        {
            return {};
        }
        vector<int>preorder;
        stack<TreeNode*>s;
        //firstly we have to push the root into the stack
        s.push(root);

        while(!s.empty())
        {
            TreeNode* temp=s.top();
            s.pop();
            //if the right exist push it into the stack
            if(temp->right != NULL)
            {
                s.push(temp->right);
            }
            //if left exist then push it into the stack
            if(temp->left != NULL)
            {
                s.push(temp->left);
            }
            preorder.push_back(temp->val);
        }
        return preorder;
    }
};

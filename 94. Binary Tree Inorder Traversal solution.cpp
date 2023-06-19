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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        stack<TreeNode*>s;
        //pointer which is pointing to the root at first
        TreeNode* curr=root;

        while(true)
        {
            //here we check if curr is not null
            //if it is not NULL then move to the left of the curr
            if(curr != NULL)
            {
                //push it into the stack
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                //check whether the stack is not empty..if it is just break from the loop
                if(s.empty())
                {
                    break;
                }

                curr=s.top();
                s.pop();
                inorder.push_back(curr->val);

                //move to the right of curr pointer
                curr=curr->right;

            }
        }
        return inorder;
        
    }
};

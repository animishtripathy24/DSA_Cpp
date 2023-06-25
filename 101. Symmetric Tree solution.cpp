/*
Intuition
The left subtree and the right subtree must be mirror image of each other.Mirror image means the left is looking on the right and the right is looking on the left.

Approach
BFS using two queues

Complexity
Time complexity:O(N)
Space complexity:O(2N) because we are using two queue.
*/


Code
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
            return NULL;
        }
        return isSymmetricHelp(root->left,root->right);
        
    }

    bool isSymmetricHelp(TreeNode* left,TreeNode* right)
    {
        if(left == NULL || right==NULL)
        {
            return (left==right);
        }
        queue<TreeNode*>q1,q2;
        q1.push(left);
        q2.push(right);

        while(!q1.empty() && !q2.empty())
        {
            TreeNode* temp1=q1.front();
            TreeNode* temp2=q2.front();
            q1.pop();q2.pop();
            if(temp1->val!=temp2->val)
            {
                return 0;
            }
            if((temp1->left==NULL && temp2->right!=NULL) || (temp1->right!= NULL && temp2->left == NULL))
            {
                return 0;
            }
            if((temp1->right==NULL && temp2->left!=NULL) || (temp1->left!=NULL && temp2->right==NULL))
            {
                return 0;
            }
            if(temp1->left)
            {
                q1.push(temp1->left);
            }
            if(temp1->right)
            {
                q1.push(temp1->right);
            }
            if(temp2->right)
            {
                q2.push(temp2->right);
            }
            if(temp2->left)
            {
                q2.push(temp2->left);
            }
        }

        return 1;
    }
};

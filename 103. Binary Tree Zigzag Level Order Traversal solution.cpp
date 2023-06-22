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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        //edge case
        if(root == NULL)
        {
            return {};
        }
        int flag=1;
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;

        while(!q.empty())
        {
            vector<int>level;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                root=q.front();
                q.pop();
                if(root->left)
                {
                    q.push(root->left);
                }
                if(root->right)
                {
                    q.push(root->right);
                }
                level.push_back(root->val);
            }
            if(flag)
            {
                ans.push_back(level);
            }
            else
            {
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            flag=!flag;
        }

        return ans;
    }
};

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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
        {
            return {};
        }

        queue<pair<TreeNode*,int>>q;//{node,level}
        map<int,int>m;//{level,node->data}

        //at first we have to insert the root node with level zero
        q.push({root,0});

        //iterate through the queue
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            m[it.second]=node->val;
            if(node->left)
            {
                q.push({node->left,it.second+1});
            }
            if(node->right)
            {
                q.push({node->right,it.second+1});
            }
        }
        vector<int>ans;
        for(auto &value:m)
        {
            ans.push_back(value.second);
        }

        return ans;

        
    }
};

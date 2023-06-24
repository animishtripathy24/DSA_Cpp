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
    int findBottomLeftValue(TreeNode* root) {

        if(root==NULL)
        {
            return -1;
        }
        //creating a max heap
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;

        map<int,int>m;

        queue<pair<TreeNode*,int>>q;//{node,level}

        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            if(m.find(it.second)==m.end())
            {
                m[it.second]=node->val;
            }

            if(node->left)
            {
                q.push({node->left,it.second+1});
            }
            if(node->right)
            {
                q.push({node->right,it.second+1});
            }

        }

        for(auto &value:m)
        {
            pq.push({value.first,value.second});
        }

        return pq.top().second;

        
    }
};

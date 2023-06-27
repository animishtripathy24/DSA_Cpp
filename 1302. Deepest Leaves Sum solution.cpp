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
    int deepestLeavesSum(TreeNode* root) {
        map<int,vector<int>>m;
        queue<pair<TreeNode*,int>>q;
        //at first we have to push with level 0;
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            TreeNode* curr=it.first;
            m[it.second].push_back(curr->val);
            if(curr->left)
            {
                q.push({curr->left,it.second+1});
            }
            if(curr->right)
            {
                q.push({curr->right,it.second+1});
            }
        }
        int maxi=INT_MIN;
        for(auto &value:m)
        {
            maxi=max(maxi,value.first);
        }
        for(auto &value:m)
        {
            if(maxi==value.first)
            {
                int sum=0;
                for(auto &it:value.second)
                {
                    sum+=it;
                }
                return sum;
            }
        }
        return -1;
    }
};

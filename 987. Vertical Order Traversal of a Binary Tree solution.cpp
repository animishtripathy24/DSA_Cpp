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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //data structures to be used...map and queue
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;

        //at first we have to insert the root with vertical and level as zero
        q.push({root,{0,0}});

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int x=it.second.first;
            int y=it.second.second;
            m[x][y].insert(node->val);
            if(node->left)
            {
                q.push({node->left,{x-1,y+1}});//(vertical-1) and (level+1)
            }
            if(node->right)
            {
                q.push({node->right,{x+1,y+1}});//(vertical+1) and (level+1)
            }
        }
        vector<vector<int>>ans;
        //basically we have to store the multiset in the form of a list
        for(auto &it:m)
        {
            vector<int>v;
            for(auto &value:it.second)
            {
                for(auto it=value.second.begin();it != value.second.end();++it)
                {
                    v.push_back(*(it));
                }
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};

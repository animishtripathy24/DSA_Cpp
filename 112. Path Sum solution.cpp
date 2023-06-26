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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right== NULL && root->val==targetSum)
        {
            return 1;
        }
        bool final=false;
        vector<int>v;
        check(root,targetSum,v,final);
        return final;
        
    }
    void check(TreeNode* root,int targetSum,vector<int>&v,bool &final)
    {
        if(!root)
        {
            return;
        }
        if(root->right==NULL && root->left==NULL)
        {
            v.push_back(root->val);
            int sum=accumulate(v.begin(),v.end(),0);
            if(sum==targetSum)
            {
                final=true;
            }
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        check(root->left,targetSum,v,final);
        check(root->right,targetSum,v,final);
        v.pop_back();

        return;


    }
};

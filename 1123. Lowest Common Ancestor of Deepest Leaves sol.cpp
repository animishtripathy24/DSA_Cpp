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
private:
    int getHeight(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int left=getHeight(root->left);
        int right=getHeight(root->right);
        return (1+max(left,right));
    }

    TreeNode* LCA(TreeNode* root,TreeNode* &p,TreeNode* &q)
    {
        if(root == NULL || root == p || root == q)
        {
            return root;
        }
        TreeNode* left=LCA(root->left,p,q);
        TreeNode* right=LCA(root->right,p,q);
        if(left == NULL)
        {
            return right;
        }
        if(right == NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }

    TreeNode* findLCA(vector<TreeNode*>&ans,TreeNode* root)
    {
        TreeNode* res=ans[0];
        for(int i=1;i<ans.size();i++)
        {
            res=LCA(root,res,ans[i]);
        }
        return res;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //at first we have to find the height of the binary tree
        int height=getHeight(root);
        vector<TreeNode*>ans;
        queue<TreeNode*>q;
        q.push(root);
        int curr_level=1;
        while(!q.empty())
        {
            if(curr_level==height)
            {
                while(!q.empty())
                {
                    ans.push_back(q.front());
                    q.pop();
                }
                break;
            }
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            curr_level++;
        }
        if(ans.size()==1)
        {
            return ans[0];
        }
        return findLCA(ans,root);
    }
};

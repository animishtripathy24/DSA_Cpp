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
    void findPath(TreeNode* root,int target,string &ans,string &ds)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->val == target)
        {
            ans+=ds;
            return;
        }
        if( root->left)
        {
            ds.push_back('L');
            findPath(root->left,target,ans,ds);
            ds.pop_back();
        }
        if(root->right)
        {
            ds.push_back('R');
            findPath(root->right,target,ans,ds);
            ds.pop_back();
        }
    }
    TreeNode* getlca(TreeNode* root,int p,int q)
    {
        if( root == NULL || root->val == p || root->val == q)
        {
            return root;
        }
        TreeNode* left = getlca(root->left,p,q);
        TreeNode* right = getlca(root->right,p,q);
        if(left == NULL)
        {
            return right;
        }
        else if(right == NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = getlca(root,startValue,destValue);
        string ds,temp1,temp2;
        findPath(lca,startValue,temp1,ds);
        ds.clear();
        findPath(lca,destValue,temp2,ds);
        // cout << temp1 << " " << temp2 << endl;
        if(temp1.size() != 0 && temp2.size() != 0)
        {
            string ans="";
            for(int i=0;i<temp1.size();i++)
            {
                ans.push_back('U');
            }
            for(int i=0;i<temp2.size();i++)
            {
                ans.push_back(temp2[i]);
            }
            return ans;
        }
        else if(temp1.size()==0 && temp2.size() != 0)
        {
            return temp2;
        }
        else if(temp1.size() != 0 && temp2.size() == 0)
        {
            string ans;
            for(int i=0;i<temp1.size();i++)
            {
                ans.push_back('U');
            }
            return ans;
        }
        return "";
    }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void check(TreeNode* root,vector<int>&ans,vector<int>&path,int b)
{
    if(root==NULL)
    {
        return;
    }
    if(root->val==b)
    {
        path.push_back(root->val);
        for(int i=0;i<path.size();i++)
        {
            ans.push_back(path[i]);
        }
        path.pop_back();
    }
    path.push_back(root->val);
    check(root->left,ans,path,b);
    check(root->right,ans,path,b);
    path.pop_back();
    return;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    if(A==NULL)
    {
        return {};
    }
    if(A->left==NULL && A->right==NULL)
    {
        return {A->val};
    }
    vector<int>ans;
    vector<int>path;
    check(A,ans,path,B);
    return ans;
}

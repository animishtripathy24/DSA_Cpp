#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int solve(TreeNode<int>* root,long long int &res)
{
    if(root == NULL)
    {
        return 0;
    }
    if(!root->left && !root->right)
    {
        return root->val;
    }
    int left = solve(root->left,res);
    int right = solve(root->right,res);

    if(root->left && root->right)
    {
        res = max(res,(left + right + root->val)*1LL);
        return root->val + max(left,right);
    }
    else if(root->left==NULL)
    {
        return right + root->val;
    }
    else
    {
        return left + root->val;
    }
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    if(root == NULL)
    {
        return -1;
    }
    long long res = LLONG_MIN;
    solve(root,res);
    return res == LLONG_MIN ? -1 : res;
}

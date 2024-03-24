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
    void findPath(TreeNode* root,int targetSum,int &count,long long &sum)
    {
        if(!root)
        {
            return;
        }
        sum+=root->val;
        if(sum == targetSum)
        {
            count++;
        }
        findPath(root->left,targetSum,count,sum);
        findPath(root->right,targetSum,count,sum);
        sum-=root->val;
        return;
    }
    void solve(TreeNode* root,int targetSum,int &count)
    {
        if(!root) return;
        long long sum=0L;
        findPath(root,targetSum,count,sum);
        solve(root->left,targetSum,count);
        solve(root->right,targetSum,count);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        solve(root,targetSum,count);
        return count;
    }
};

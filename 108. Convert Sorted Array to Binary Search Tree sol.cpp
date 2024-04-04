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
    TreeNode* inorderToBST(vector<int>&nums,int start,int end)
    {
        if(start>end) 
            return NULL;
        
        int mid=(start+end)>>1;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=inorderToBST(nums,start,mid-1);
        root->right=inorderToBST(nums,mid+1,end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return inorderToBST(nums,0,nums.size()-1);
    }
};

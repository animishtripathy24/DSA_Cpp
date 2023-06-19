class Solution {
public:
    //inorder traversal
    void inorder(vector<int>&leaf1,TreeNode* root)
    {
        //base case
        if(root == NULL)
        {
            return;
        }

        //pehle left ke liye call jayega...
        inorder(leaf1,root->left);
        if(root->left ==NULL && root->right==NULL)
        {
            leaf1.push_back(root->val);
        }
        //phir right ke liye call jayega
        inorder(leaf1,root->right);
    }
    //inorder traversal
    void inorder1(vector<int>&leaf2,TreeNode* root)
    {
        //base case
        if(root == NULL)
        {
            return;
        }

        //pehle left ke liye call jayega...
        inorder1(leaf2,root->left);
        if(root->left ==NULL && root->right==NULL)
        {
            leaf2.push_back(root->val);
        }
        //phir right ke liye call jayega
        inorder1(leaf2,root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaf1,leaf2;

        inorder(leaf1,root1);
        inorder1(leaf2,root2);

        if(leaf1.size() != leaf2.size())
        {
            return 0;
        }

        for(int i=0;i<leaf1.size();i++)
        {
            if(leaf1[i]!=leaf2[i])
            {
                return 0;
            }
        }

        return 1;
        
    }
};

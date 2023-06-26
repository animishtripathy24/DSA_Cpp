/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    bool isSumTree(Node* root)
    {
        bool final=true;
        if(root==NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right==NULL)
        {
            return 1;
        }
        check(root,final);
        return final;
    }
    int check(Node* root,bool &final)
    {
        if(root== NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right==NULL)
        {
            return root->data;
        }
        int lh=check(root->left,final);
        int rh=check(root->right,final);

        if(lh+rh != root->data)
        {
            final=false;
        }
        return (root->data+lh+rh);
    }
};

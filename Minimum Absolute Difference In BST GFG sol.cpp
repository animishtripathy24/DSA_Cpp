/*The Node structure is defined as
struct Node 
{
    int data;
    Node *left;
    Node *right;

};
*/

class Solution
{
    private:
    void inorder(Node* root,int &mini,Node* &prev)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,mini,prev);
        if(prev)
        {
            mini=min(mini,abs(prev->data-root->data));
        }
        prev=root;
        inorder(root->right,mini,prev);
    }
    public:
    int absolute_diff(Node *root)
    {
        int mini=INT_MAX;
        Node* prev=NULL;
        inorder(root,mini,prev);
        return mini;
    }
};

Node* findLastRightChildOnLeft(Node* root)
{
    if(root->right ==NULL)
    {
        return root;
    }
    return findLastRightChildOnLeft(root->right);
}
Node* helper(Node* root)
{
    if(root->left==NULL)
    {
        return root->right;
    }
    if(root->right==NULL)
    {
        return root->left;
    }
    Node* rightChild=root->right;
    Node* lastRight=findLastRightChildOnLeft(root->left);
    lastRight->right=rightChild;
    return root->left;
}
// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data == X)
    {
        return helper(root);
    }
    
    Node* dummy=root;
    while(root)
    {
        if(root->data > X) //it means that key must lie on the left subtree
        {
            if(root->left != NULL && root->left->data==X)
            {
                root->left=helper(root->left);
                break;
            }
            else
            {
                root=root->left;
            }
        }
        else
        {
            if(root->right != NULL && root->right->data==X)
            {
                root->right=helper(root->right);
                break;
            }
            else
            {
                root=root->right;
            }
        }
    }
    return dummy;
}

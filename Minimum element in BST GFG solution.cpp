// Function to find the minimum element in the given BST.

/*
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/
int minValue(Node* root) {
    if(root==NULL)
    {
        return -1;
    }
    if(root->left==NULL)
    {
        return root->data;
    }
    while(root->left)
    {
        root=root->left;
    }
    return root->data;
}

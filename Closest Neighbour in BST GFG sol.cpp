// User function Template for C++
/*
//Structure of the Node of the BST is as
struct Node {
    int key;
    Node* left, *right;
};


   'N' is the element
   'size' is the total element in BST
  */

class Solution {
  public:
    int findMaxForN(Node* root, int n) {
        int ele=-1;
        while(root)
        {
            if(root->key > n)
            {
                root=root->left;
            }
            else
            {
                ele=root->key;
                root=root->right;
            }
        }
        return ele;
    }
};

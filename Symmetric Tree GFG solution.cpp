/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
        if(root==NULL)
        {
            return 1;
        }
	    return isSymmetricHelp(root->left,root->right);
    }
    bool isSymmetricHelp(Node* left,Node* right)
    {
        if(left == NULL || right==NULL)
        {
            return (left==right);
        }
        queue<Node*>q1,q2;
        q1.push(left);
        q2.push(right);

        while(!q1.empty() && !q2.empty())
        {
            Node* temp1=q1.front();
            Node* temp2=q2.front();
            q1.pop();q2.pop();
            if(temp1->data!=temp2->data)
            {
                return 0;
            }
            if((temp1->left==NULL && temp2->right!=NULL) || (temp1->right!= NULL && temp2->left == NULL))
            {
                return 0;
            }
            if((temp1->right==NULL && temp2->left!=NULL) || (temp1->left!=NULL && temp2->right==NULL))
            {
                return 0;
            }
            if(temp1->left)
            {
                q1.push(temp1->left);
            }
            if(temp1->right)
            {
                q1.push(temp1->right);
            }
            if(temp2->right)
            {
                q2.push(temp2->right);
            }
            if(temp2->left)
            {
                q2.push(temp2->left);
            }
        }

        return 1;
    }
};

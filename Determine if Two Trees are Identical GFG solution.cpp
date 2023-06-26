//Determine if Two Trees are Identical
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *p, Node *q)
    {
        if(p == NULL || q == NULL)
        {
            return (p==q);
        }
        queue<Node*>q1,q2;
        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty())
        {
            p=q1.front();
            q=q2.front();
            q1.pop(); q2.pop();

            if(p->data != q->data)
            {
                return 0;
            }
            if((p->left != NULL && q->left==NULL) || (p->left == NULL && q->left!=NULL))
            {
                return 0;
            }
            if((p->right != NULL && q->right==NULL) || (p->right == NULL && q->right!=NULL))
            {
                return 0;
            }

            if(p->left)
            {
                q1.push(p->left);
            }
            if(p->right)
            {
                q1.push(p->right);
            }
            if(q->left)
            {
                q2.push(q->left);
            }
            if(q->right)
            {
                q2.push(q->right);
            }
        }
        return 1;
        
        
    }
};

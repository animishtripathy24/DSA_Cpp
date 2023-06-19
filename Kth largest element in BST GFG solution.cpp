/*
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    void preorder(priority_queue<int>&pq,Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        
        pq.push(root->data);
        preorder(pq,root->left);
        preorder(pq,root->right);
    }
    int kthLargest(Node *root, int K)
    {
        //creating max heap
        priority_queue<int>pq;
        
        preorder(pq,root);
        
        int count=1;
        
        while(!pq.empty())
        {
            if(count==K)
            {
                return pq.top();
            }
            count++;
            pq.pop();
            
        }
        
        return -1;
    }
};

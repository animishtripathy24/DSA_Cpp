//User function Template for C++

/*struct Node
{
	int data;
	struct Node *left, *right;
};*/

class Solution
{
    private:
    void solve(Node* &root,int &sum)
    {
        if(!root)
        {
            return;
        }
        solve(root->right,sum);
        int res=root->data;
        root->data=sum;
        sum+=res;
        solve(root->left,sum);
        return;
    }
    public:
    void transformTree(struct Node *root)
    {
        int sum=0;
        Node* curr=root;
        solve(root,sum);
        root=curr;
    }
};

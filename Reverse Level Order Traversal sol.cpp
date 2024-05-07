/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* curr=q.front();
            q.pop();
            ans.push_back(curr->data);
            if(curr->right)
            {
                q.push(curr->right);
            }
            if(curr->left)
            {
                q.push(curr->left);
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

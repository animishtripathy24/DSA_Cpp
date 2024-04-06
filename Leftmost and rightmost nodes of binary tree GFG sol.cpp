/* Function to print corner node at each level */

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
void printCorner(Node *root)
{

    queue<Node*>q;
    q.push(root);
    vector<int>v;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(i==0)
            {
                v.push_back(curr->data);
            }
            if(i==size-1 && size !=1)
            {
                v.push_back(curr->data);
            }
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
    }
    for(auto &it:v)
    {
        cout << it << " ";
    }

}

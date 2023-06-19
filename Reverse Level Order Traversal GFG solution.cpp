/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    vector<vector<int>>ans;
    if(root == NULL)
    {
        return {};
    }
    //firstly we have to declare a queue
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++)
        {
            Node* temp= q.front();
            q.pop();
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    reverse(ans.begin(),ans.end());
    vector<int>res;
    for(auto &it:ans)
    {
        for(auto &value:it)
        {
            res.push_back(value);
        }
    }
    
    return res;
}

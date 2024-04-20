/*Complete the function below
Node is as follows:
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
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
void solve(Node* root,vector<pair<Node*,pair<int,Node*>>>&v)
{
    queue<Node*>q;
    q.push(root);
    v.push_back({root,{0,new Node(-1)}});
    int curr_level=0;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* curr=q.front();
            q.pop();
            
            if(curr->left)
            {
                q.push(curr->left);
                v.push_back({curr->left,{curr_level,curr}});
            }
            if(curr->right)
            {
                q.push(curr->right);
                v.push_back({curr->right,{curr_level,curr}});                
            }
        }
        curr_level++;
    }
    
}
bool isCousins(Node *root, int a, int b)
{
    if(a==root->data || b==root->data)
    {
        return 0;
    }
    vector<pair<Node*,pair<int,Node*>>>v;   //{Node,{depth,parent}}
    solve(root,v);
    int depth1,depth2,parent1,parent2;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].first->data == a)
        {
            depth1=v[i].second.first;
            parent1=v[i].second.second->data;
        }
        if(v[i].first->data == b)
        {
            depth2=v[i].second.first;
            parent2=v[i].second.second->data;
        }
    }
    if(depth1==depth2)
    {
        if(parent1==parent2)
        {
            return 0;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

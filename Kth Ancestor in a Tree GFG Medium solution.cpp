//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function


void make_parent(Node* root,unordered_map<Node*,Node*>&parent)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();
        if(curr->left !=NULL)
        {
            parent[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right)
        {
            parent[curr->right]=curr;
            q.push(curr->right);
        }
    }
}

void inorder(Node* root,int node,Node* &target)
{
    if(!root)
    {
        return;
    }
    inorder(root->left,node,target);
    if(root->data == node)
    {
        target=root;
    }
    inorder(root->right,node,target);
}
int kthAncestor(Node *root, int k, int node)
{
    if(!root)
    {
        return 0;
    }
    
    //saare node ka parent bana lena hai...
    unordered_map<Node*,Node*>parent;
    make_parent(root,parent);
    Node* target=NULL;
    inorder(root,node,target);
    unordered_map<Node*,bool>visited;
    queue<Node*>q;
    q.push(target);
    visited[target]=true;
    int curr_level=0;
    
    while(!q.empty())
    {
            if(curr_level==k)
            {
                break;
            }
            curr_level++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node* curr=q.front();
                q.pop();
                if(parent[curr] && visited[parent[curr]]==false)
                {
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
            }
    }
    vector<int>ans;
    while(!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    return (ans.size()==0)? -1:*min_element(ans.begin(),ans.end());

    
}

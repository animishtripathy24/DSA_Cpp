//User function Template for C++

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
class Solution {
void preorder(Node* root,int &target,Node* &targetNode)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==target)
    {
        targetNode=root;
    }
    preorder(root->left,target,targetNode);
    preorder(root->right,target,targetNode);
}

void findParents(Node* root,unordered_map<Node*,Node*>&m)
{
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();
        if(curr->left != NULL)
        {
            m[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right != NULL)
        {
            m[curr->right]=curr;
            q.push(curr->right);
        }
        
    }
    
}
  public:
    int minTime(Node* root, int target) 
    {
        Node* targetNode;
        //to keep the track of the parent node we use a hashMap
        unordered_map<Node*,Node*>parent;
        findParents(root,parent);
        preorder(root,target,targetNode);
        //to keep track of the visited node we have to use another hashMap
        unordered_map<Node*,bool>visited;
        queue<Node*>q;
        q.push(targetNode);
        visited[targetNode]=true;
        int curr_level=0;
        while(!q.empty())
        {
            int size=q.size();
            curr_level++;
            for(int i=0;i<size;i++)
            {
                Node* curr=q.front();
                q.pop();
                if(curr->left && visited[curr->left]==false)
                {
                    visited[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right && visited[curr->right]==false)
                {
                    visited[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent[curr] && visited[parent[curr]]==false)
                {
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
                
            }
        }
        return curr_level-1;
    }
};

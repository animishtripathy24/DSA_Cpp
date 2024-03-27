/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
private:
    void makeParent(Node* root,unordered_map<Node*,Node*>&parent)
    {
        //at first we have to declare a queue data structure
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            
            if(curr->left)
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
    void findTarget(Node* root,int target,Node* &targetNode)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->data==target)
        {
            targetNode=root;
        }
        findTarget(root->left,target,targetNode);
        findTarget(root->right,target,targetNode);
    }
public:
    int sum_at_distK(Node* root, int target, int k)
    {
        // at first we have to make parent 
        unordered_map<Node*,Node*>parent;
        makeParent(root,parent);
        //then we have to declare a visited map
        unordered_map<Node*,bool>vis;
        //then we have to find the target node
        Node* targetNode=NULL;
        findTarget(root,target,targetNode);
        //mark the targetNode in the map as 1
        vis[targetNode]=true;
        queue<Node*>q;
        int curr_level=0;
        q.push(targetNode);
        int sum=0;
        while(!q.empty())
        {
            int size=q.size();
            if(curr_level==k)
            {
                break;
            }
            for(int i=0;i<size;i++)
            {
                Node* curr=q.front();
                q.pop();
                sum+=curr->data;
                
                if(curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent[curr] && !vis[parent[curr]])
                {
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
                }
            }
            curr_level++;
        }
        while(!q.empty())
        {
            sum+=q.front()->data;
            q.pop();
        }
        return sum;
    }
};

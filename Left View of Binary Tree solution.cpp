
/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    if(root==NULL)
    {
        return {};
    }
   //declaring a couple of data structure
   map<int,int>m;
   queue<pair<Node*,int>>q;
   
   //at first we have to insert the root with level 0
   q.push({root,0});
   
   while(!q.empty())
   {
       auto it=q.front();
       q.pop();
       Node* node=it.first;
       if(m.find(it.second)==m.end())
       {
           m[it.second]=node->data;
       }
       if(node->left)
       {
           q.push({node->left,it.second+1});
       }
       if(node->right)
       {
           q.push({node->right,it.second+1});
       }
       
   }
   vector<int>ans;
   for(auto &value:m)
   {
       ans.push_back(value.second);
   }
   
   return ans;
}

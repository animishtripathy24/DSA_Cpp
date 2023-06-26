/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
    if(root==NULL)
    {
        return {};
    }
   vector<int>ans;
   queue<Node*>q;
   
   q.push(root);
   while(!q.empty())
   {
       Node* curr=q.front();
       q.pop();
       while(curr)
       {
           if(curr->left != NULL)
           {
               q.push(curr->left);
           }
           ans.push_back(curr->data);
           curr=curr->right;
       }
   }
   return ans;
   
}

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       queue<Node*>q;
       //at first we have to insert the root node
       q.push(root);
       int count=1;
       int sum_odd=0;
       int sum_even=0;
       
       while(!q.empty())
       {
           vector<int>level;
           int size=q.size();
           for(int i=0;i<size;i++)
           {
               root=q.front();
               q.pop();
               if(root->left)
               {
                   q.push(root->left);
               }
               if(root->right)
               {
                   q.push(root->right);
               }
               level.push_back(root->data);
           }
           if(count & 1)
           {
               sum_odd+=accumulate(level.begin(),level.end(),0);
           }
           else
           {
               sum_even+=accumulate(level.begin(),level.end(),0);
           }
           count++;
       }
       
       return (sum_odd-sum_even);
    }
};

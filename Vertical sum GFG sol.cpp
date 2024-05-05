/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        map<int,int>m;
        queue<pair<Node*,int>>q; //{root,level}
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node* curr=it.first;
            int level=it.second;
            
            m[level]+=curr->data;
            
            if(curr->left)
            {
                q.push({curr->left,level-1});
            }
            if(curr->right)
            {
                q.push({curr->right,level+1});
            }
        }
        vector<int>ans;
        for(auto &it:m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

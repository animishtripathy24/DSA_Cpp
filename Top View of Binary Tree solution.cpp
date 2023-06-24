/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //we have to take a couple of data structure
        queue<pair<Node*,int>>q; //{root,vertical}
        
        //we want ascending order of vertical hence map taken not unordered_map
        map<int,int>m;//{vertical,node->data} 
        
        //initially we have to put the root into the queue
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node* temp=it.first;
            //check whether the vertical exist or not 
            if(m.find(it.second)==m.end())
            {
                m[it.second]=temp->data;
            }
            
            //if left of root exist then push it into the queue
            if(temp->left)
            {
                q.push({temp->left,(it.second-1)});
            }
            
            //if right of root exist then push into the queue
            if(temp->right)
            {
                q.push({temp->right,(it.second+1)});
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

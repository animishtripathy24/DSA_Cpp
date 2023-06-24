class Solution {
  public:
    vector<int> bottomView(Node *root) {
        //we will declare a queue ds which basically store the node and the level
        queue<pair<Node*,int>> q;//{node,vertical}
        
        //we want the vertical in ascending order hence map ds
        map<int,int>m;//{vertical,node->data} 
        
        //at first we have to insert the root node with level zero into the queue
        q.push({root,0});
        
        //iterate over the queue(LEVEL ORDER TRAVERSAL)
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node* temp=it.first;
            //every time just change the value in map
            m[it.second]=temp->data;
            if(temp->left)
            {
                q.push({temp->left,it.second-1});
            }
            if(temp->right)
            {
                q.push({temp->right,it.second+1});
            }
        }
        
        vector<int>ans;
        for(auto &value:m)
        {
            ans.push_back(value.second);
        }
        
        return ans;
    }
};

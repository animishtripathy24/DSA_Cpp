class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //declaring the data structures
        map<int,map<int,vector<int>>>m;
        queue<pair<Node*,pair<int,int>>>q;
        
        //at first we have to insert the root
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int x=it.second.first;
            int y=it.second.second;
            m[x][y].push_back(node->data);
            if(node->left)
            {
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right)
            {
                q.push({node->right,{x+1,y+1}});
            }
        }
        vector<int>v;
        for(auto &it:m)
        {
            for(auto &value:it.second)
            {
                for(auto it=value.second.begin();it != value.second.end();++it)
                {
                    v.push_back(*(it));
                }
            }
        }
        return v;
        
    }
};

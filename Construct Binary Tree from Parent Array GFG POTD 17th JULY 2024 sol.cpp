class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        unordered_map<int,Node*>m;
        Node* root = NULL;
        for(int i=0;i<parent.size();i++)
        {
            Node* newNode = new Node(i);
            m[i]=newNode;
        }
        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]==-1)
            {
                root = m[i];
            }
            else
            {
                Node* parentNode = m[parent[i]];
                if (!parentNode->left) 
                {
                    parentNode->left = m[i];
                } 
                else 
                {
                    parentNode->right = m[i];
                }
            }
        }
        return root;
    }
};

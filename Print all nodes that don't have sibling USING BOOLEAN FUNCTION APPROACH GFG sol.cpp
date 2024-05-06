//User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

bool solve(Node* curr,Node* root,vector<int>&ans)
{
    if(curr == NULL)
    {
        return 0;
    }
    bool left=solve(curr->left,root,ans);
    bool right=solve(curr->right,root,ans);
    if((left && !right) || (!left && right))
    {
        if(curr->left)
        {
            ans.push_back(curr->left->data);
        }
        if(curr->right)
        {
            ans.push_back(curr->right->data);
        }
    }
    return 1;
}
vector<int> noSibling(Node* node)
{
    Node* curr=node;
    vector<int>ans;
    solve(curr,node,ans);
    if(ans.size()==0)
    {
        return {-1};
    }
    sort(ans.begin(),ans.end());
    return ans;
}

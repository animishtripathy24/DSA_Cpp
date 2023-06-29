/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*You are required to complete below method */
void solve(Node* root,vector<string>&ans,vector<int>&path)
{
    if(!root)
    {
        return;
    }
    if(root->left == NULL && root->right==NULL)
    {
        path.push_back(root->data);
        string temp;
        for(int i=0;i<path.size();i++)
        {
            temp+=to_string(path[i]);
        }
        ans.push_back(temp);
        path.pop_back();
        return;
    }
    path.push_back(root->data);
    solve(root->left,ans,path);
    solve(root->right,ans,path);
    path.pop_back();
    return;
}
long long treePathsSum(Node *root)
{
    vector<string>ans;
    vector<int>path;
    solve(root,ans,path);
    long long int sum=0;
    for(int i=0;i<ans.size();i++)
    {
        sum+=stoi(ans[i]);
    }
    return sum;
}

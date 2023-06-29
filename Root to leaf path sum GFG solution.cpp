/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution
{
    private:
    void check(Node* root,int sum,vector<int>&ans,bool &final)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->data);
            if(accumulate(ans.begin(),ans.end(),0)==sum)
            {
                final=true;
            }
            ans.pop_back();
            return;
        }
        ans.push_back(root->data);
        check(root->left,sum,ans,final);
        check(root->right,sum,ans,final);
        ans.pop_back();
        return;
    }
    public:
    bool hasPathSum(Node *root, int S) {
    bool final=false;
    vector<int>ans;
    check(root,S,ans,final);
    return final;
}
};

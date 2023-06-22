/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
private:
    void addLeftBoundary(Node* root,vector<int>&ans)
    {
        Node* curr=root->left;
        while(curr)
        {
            if(curr->left != NULL || curr->right != NULL)
            {
                ans.push_back(curr->data);
            }
            if(curr->left != NULL)
            {
                curr=curr->left;
            }
            else
            {
                curr=curr->right;
            }
        }
    }
    void addLeaves(Node* root,vector<int>&ans)
    {
        //base case
        if(root == NULL)
        {
            return;
        }
    
        //pehle left ke liye call jayega...
        addLeaves(root->left,ans);
        if(root->left == NULL && root->right==NULL)
        {
            ans.push_back(root->data);
        }
        //phir right ke liye call jayega
        addLeaves(root->right,ans);
    }
    void addRightBoundary(Node* root,vector<int>&ans)
    {
        stack<int>s;
        Node* curr=root->right;
        while(curr)
        {
            if(curr->left != NULL || curr->right != NULL)
            {
                s.push(curr->data);
            }
            if(curr->right != NULL)
            {
                curr=curr->right;
            }
            else
            {
                curr=curr->left;
            }
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
    }
public:
    vector <int> boundary(Node *root)
    {
        if(root==NULL)
        {
            return {};
        }
        vector<int>ans;
        if(root->left != NULL || root->right != NULL)
        {
            ans.push_back(root->data);
        }
        addLeftBoundary(root,ans);
        addLeaves(root,ans);
        addRightBoundary(root,ans);
        return ans;
    }
};

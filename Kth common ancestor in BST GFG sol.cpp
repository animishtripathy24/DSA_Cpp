//User function Template for C++

/*// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};*/


class Solution
{
    private:
    Node* LCA(Node* root,int &p,int &q,vector<int>&ans)
    {
        if(!root) return NULL;
        ans.push_back(root->data);
        if(p<root->data && q<root->data)
        {
            
            return LCA(root->left,p,q,ans);
        }
        else if(p>root->data && q>root->data)
        {
            
            return LCA(root->right,p,q,ans);
        }
        else
        {
            return root;
        }
    }
    public:
    
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
            vector<int>ans;
            Node* newRoot=LCA(root,x,y,ans);
            // for(auto &it:ans)
            // {
            //     cout << it << "  ";
            // }
            if(ans.size()<k)
            {
                return -1;
            }
            return ans[ans.size()-k];
            // cout << ans.size();
            // cout << endl;
            // return 1;
    }
};

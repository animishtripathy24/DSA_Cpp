/*
Given a Binary Tree and a target key, you need to find all the ancestors of the given target key.

              1
            /   \
          2      3
        /  \
      4     5
     /
    7
Key: 7
Ancestor: 4 2 1
Example 1:

Input:
        1
      /   \
     2     3
target = 2
Output: 1
Example 2:

Input:
         1
       /   \
      2     3
    /  \   /  \
   4    5 6    8
  /
 7
target = 7
Output: 4 2 1
Your Task:
Your task is to complete the function Ancestors() that finds all the ancestors of the key in the given binary tree.
Note:
The return type is
cpp: vector
Java: ArrayList
python: list

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for the recursion stack.
*/



/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution{
private:
    void solve(struct Node* root,int target,vector<int>&path,vector<int>&ans)
    {
        if(!root)
        {
            return;
        }
        if(root->data == target)
        {
            for(int i=path.size()-1;i>=0;i--)
            {
                ans.push_back(path[i]);
            }
            return;
        }
        path.push_back(root->data);
        solve(root->left,target,path,ans);
        solve(root->right,target,path,ans);
        path.pop_back();
        return;
    }
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target)
    {
         if(!root)
         {
             return {};
         }
         vector<int>path;
         vector<int>ans;
         solve(root,target,path,ans);
         return ans;
    }
};

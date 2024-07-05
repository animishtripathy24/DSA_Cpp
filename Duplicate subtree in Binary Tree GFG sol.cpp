/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  private:
    string getTreeSubString(Node* root,unordered_map<string,int>&m,int &count)
    {
        if(root == NULL)
        {
            return "N";
        }
        // if(!root->left && !root->right)
        // {
        //     return to_string(root->data);
        // }
        string s;
        s.push_back(root->data);
        s+=","+getTreeSubString(root->left,m,count)+","+getTreeSubString(root->right,m,count);
        // cout << s << endl;
        if(s.size()!=5 && m[s]==1)
        {
            // cout << s << endl;
            count++;
        }
        m[s]++;
        return s;
    }
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        unordered_map<string,int>m;
        int count=0;
        getTreeSubString(root,m,count);
        // cout << count << endl;
        if(count>0)
        {
            return 1;
        }
        return 0;
    }
};

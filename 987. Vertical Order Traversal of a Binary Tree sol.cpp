class Solution {
private:
    void solve(TreeNode* root,int vertical,int level,map<int,map<int,multiset<int>>>&m)
    {
        if(!root)
        {
            return;
        }
        m[vertical][level].insert(root->val);
        solve(root->left,vertical-1,level+1,m);
        solve(root->right,vertical+1,level+1,m);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m;
        solve(root,0,0,m);
        vector<vector<int>>ans;
        for(auto it:m)
        {
            vector<int>temp;
            for(auto itt:it.second)
            {
                for(auto ittt=itt.second.begin();ittt!=itt.second.end();ittt++)
                {
                    temp.push_back(*ittt);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        //at first we have to make a map
        map<int,vector<int>>mp;
        int n = mat.size();
        //step-1 : store them in a map
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        
        //step-2 : reverse them accordingly in the map and store it in a vector
        vector<int>ans;
        for(auto &value:mp)
        {
            reverse(value.second.begin(),value.second.end());
            for(auto &it:value.second)
            {
                ans.push_back(it);
            }
        }
        return ans;
    }
};

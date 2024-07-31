class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        map<int,vector<int>>mp;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i+j].push_back(matrix[i][j]);
            }
        }
        vector<int>ans;
        for(auto &it:mp)
        {
            for(auto &value : it.second)
            {
                ans.push_back(value);
            }
        }
        return ans;
    }
};

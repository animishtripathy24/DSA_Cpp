class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // step-1: store them in the map according to (i-j) rule 
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i-j].push_back(matrix[i][j]);
            }
        }
        
        // step-2 : sort them
        for(auto &value:mp)
        {
            sort(value.second.begin(),value.second.end());
        }
        
        //step-3: fill in the matrix from the back
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                matrix[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return matrix;
    }
};

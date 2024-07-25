class Solution {
  private:
    void solve(int row,int col,vector<vector<int>>&matrix,
    vector<string>&ans,string &ds,string &dir,
    vector<int>&delrow,vector<int>&delcol,vector<vector<int>>&vis)
    {
        int n = matrix.size();
        //base case
        if(row == n-1 && col == n-1)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow <n && ncol >= 0 && ncol <n && !vis[nrow][ncol] && matrix[nrow][ncol]== 1)
            {
                ds.push_back(dir[i]);
                vis[row][col]=1;
                solve(nrow,ncol,matrix,ans,ds,dir,delrow,delcol,vis);
                ds.pop_back();
                vis[row][col]=0;
            }
        }
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string>ans;
        //we also have to declare the visited matrix
        vector<vector<int>>vis(n,vector<int>(n,0));
        string ds = "";
        vector<int>delrow={1,0,0,-1};
        vector<int>delcol={0,-1,1,0};
        string directions="DLRU";
        if(mat[0][0]==1)
        {
            solve(0,0,mat,ans,ds,directions,delrow,delcol,vis);
        }
        return ans;
    }
};

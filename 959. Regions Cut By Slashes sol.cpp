class Solution {
private:
    void bfs(int row,int col,vector<vector<bool>>&vis,vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=true;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;

            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    //ignore the diagonal elements
                    if(abs(delrow)+abs(delcol)==2)
                    {
                        continue;
                    }
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol]==0)
                    {
                        vis[nrow][ncol]=true;
                        q.push({nrow,ncol});
                    }
                }
            }
        }       
    }
    int numIslands(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==0)
                {
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>matrix(rows*3,vector<int>(cols*3,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]=='\\')
                {
                    matrix[i*3][j*3]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3+2]=1;
                }
                else if(grid[i][j]=='/')
                {
                    matrix[i*3][j*3+2]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3]=1;
                }
            }
        }
        //counting the number of 0's (same as number of island problem)
        return numIslands(matrix);
    }
};

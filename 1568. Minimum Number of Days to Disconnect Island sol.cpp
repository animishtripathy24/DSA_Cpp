class Solution 
{
private:
    void bfs(int row,int col,vector<vector<bool>>&vis,vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
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
                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                    {
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }       
    }
    int numIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = numIslands(grid);
        if(islands > 1 || islands == 0)
        {
            return 0;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==1)
                    {
                        grid[i][j]=0;
                        int countIslands = numIslands(grid);
                        if(countIslands > 1 || countIslands == 0)
                        {
                            return 1;
                        }
                        grid[i][j]=1;
                    }
                }
            }
        }
        return 2;
    }
};

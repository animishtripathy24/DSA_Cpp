class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //at first we have to declare a visited array
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;  //{{row,col},mintime}
        // now we have to put the rotten oranges in the queue
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
            }
        }
        
        int minTime=0;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row= it.first.first;
            int col=it.first.second;
            int tm=it.second;
            minTime=max(minTime,tm);
            
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    if(abs(delrow)+abs(delcol)==2)
                    {
                        continue;
                    }
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    
                    while(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                    {
                        vis[nrow][ncol]=2;
                        q.push({{nrow,ncol},tm+1});
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < m; ++j) 
            {
                if (grid[i][j] == 1 && vis[i][j] != 2) 
                {
                    return -1;
                }
            }
        }
        return minTime;
    }
};

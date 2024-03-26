class Solution
{
private:
    void mark(int row,int col,vector<vector<int>>&vis)
    {
        int n=vis.size();
        int m =vis[0].size();
        for(int delrow=-1;delrow<=1;delrow++)
        {
            for(int delcol=-1;delcol<=1;delcol++)
            {
                //ignore the diagonal elemnts
                if(abs(delrow)+abs(delcol)==2)
                {
                    continue;
                }
                int nrow=row+delrow;
                int ncol=col+delcol;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) 
                {
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       int n=mat.size();
       int m=mat[0].size();
       
       //then we have to make a visited array
       vector<vector<int>>vis(n,vector<int>(m,0));
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(mat[i][j]==0)
               {
                   vis[i][j]=1;
                   //mark the adjacent nodes
                   mark(i,j,vis);
               }
           }
       }
       int mini=INT_MAX;
       queue<pair<int,pair<int,int>>>q;  //{dist,{row,col}}
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(j==0 && mat[i][j]==1 && !vis[i][j])
               {
                   q.push({1,{i,j}});
               }
           }
       }
       while(!q.empty())
       {
           auto it=q.front();
           q.pop();
           int dist=it.first;
           int row=it.second.first;
           int col=it.second.second;
           
           if(col==m-1)
           {
               mini=min(mini,dist);
           }
           
           for(int delrow=-1;delrow<=1;delrow++)
           {
               for(int delcol=-1;delcol<=1;delcol++)
               {
                   //ignore the diagonals
                   if(abs(delrow)+abs(delcol)==2)
                   {
                       continue;
                   }
                   int nrow=row+delrow;
                   int ncol=col+delcol;
                   if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && mat[nrow][ncol]==1 && !vis[nrow][ncol])
                   {
                       q.push({dist+1,{nrow,ncol}});
                       vis[nrow][ncol]=1;
                   }
               }
           }
       }
       if(mini==INT_MAX)
       {
           return -1;
       }
       return mini;
    }
};

class Solution 
{
    private:
    bool solve(int grid[N][N])
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int k=1;k<=9;k++)
                    {
                        if(valid(grid,i,j,k))
                        {
                            grid[i][j]=k;
                            if(solve(grid))
                            {
                                return 1;
                            }
                            else
                            {
                                grid[i][j]=0;
                            }
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    bool valid(int grid[N][N],int row,int col,int c)
    {
        for(int i=0;i<9;i++)
        {
            if(grid[i][col]==c)
            {
                return 0;
            }
            if(grid[row][i]==c)
            {
                return 0;
            }
            if(grid[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c)
            {
                return 0;
            }
        }
        return 1;
    }
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        return solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};

class Solution {
private:
    bool check(int rows, int cols, vector<vector<int>>& grid) {
        unordered_set<int> s;

        // Check if all the values are from 1 to 9
        for (int i = rows; i < rows + 3; i++) 
        {
            for (int j = cols; j < cols + 3; j++) 
            {
                if (grid[i][j] < 1 || grid[i][j] > 9 || s.find(grid[i][j]) != s.end()) 
                {
                    return false;
                }
                s.insert(grid[i][j]);
            }
        }

        // Check for rows
        for (int i = rows; i < rows + 3; i++) 
        {
            int sumRows = 0;
            for (int j = cols; j < cols + 3; j++) 
            {
                sumRows += grid[i][j];
            }
            if (sumRows != 15) 
            {
                return false;
            }
        }

        // Check for columns
        for (int i = cols; i < cols + 3; i++) 
        {
            int sumCols = 0;
            for (int j = rows; j < rows + 3; j++) 
            {
                sumCols += grid[j][i];
            }
            if (sumCols != 15) 
            {
                return false;
            }
        }

        // Check for diagonals
        int diagonalSum = grid[rows][cols] + grid[rows + 1][cols + 1] + grid[rows + 2][cols + 2];
        int antiDiagonalSum = grid[rows][cols + 2] + grid[rows + 1][cols + 1] + grid[rows + 2][cols];
        if (diagonalSum != 15 || antiDiagonalSum != 15) 
        {
            return false;
        }

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int countMagic = 0;

        // Check each possible 3x3 grid
        for (int i = 0; i < n - 2; i++) 
        {
            for (int j = 0; j < m - 2; j++) 
            {
                if (check(i, j, grid)) 
                {
                    countMagic++;
                }
            }
        }
        return countMagic;
    }
};

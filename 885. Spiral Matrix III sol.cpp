class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        vector<pair<int,int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int steps = 0;
        int direction = 0;
        ans.push_back({rStart,cStart});
        int total = (rows * cols)-1;
        int count = 1;
        while(count <= total)
        {
            if(direction == 0 || direction == 2)
            {
                steps++;
            }
            for(int i=0;i<steps;i++)
            {
                rStart += dir[direction].first;
                cStart += dir[direction].second;
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                {
                    ans.push_back({rStart,cStart});
                    count++;
                }
            }
            direction = (direction + 1) % 4;
        }
        return ans;
    }
};

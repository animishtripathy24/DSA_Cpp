class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &heights) {
        int maxi = heights[0];
        int count = 1;
        for(int i=0;i<heights.size();i++)
        {
            if(heights[i] > maxi)
            {
                count++;
                maxi = heights[i];
            }
        }
        return count;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0;
        int j= n-1;
        int maxi = INT_MIN;
        while(i<j)
        {
            int w = j-i;
            int h = min(height[i],height[j]);
            int currArea = w*h;
            maxi = max(maxi,currArea);
            if(height[i] > height[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return maxi;
    }
};

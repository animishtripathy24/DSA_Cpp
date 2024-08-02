class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int i = 0, j = 0;
        int countZeros = 0;
        int maxLength = 0;
        while (j < nums.size()) 
        {
            // Expand the window by including nums[j]
            if(nums[j] == 0) 
            {
                countZeros++;
            }
            // If zeros exceed k, shrink the window from the left
            while(countZeros > k) 
            {
                if (nums[i] == 0) 
                {
                    countZeros--;
                }
                i++;
            }
            // Update the maximum length of the window
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        return maxLength;
    }
};

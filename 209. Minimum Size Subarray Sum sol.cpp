class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int i=0;
        int j=0;
        int sum = 0;
        int mini = INT_MAX; //the minimum size of the subarray can be the whole subarray
        while(j < size)
        {   
            sum+=nums[j];
            if(sum < target)
            {
                j++;
            }
            else
            {
                mini = min(mini,j-i+1);
                while(sum >= target)
                {
                    mini = min(mini,j-i+1);
                    sum-=nums[i];
                    i++;
                }
                j++;
            }
        }
        return mini==INT_MAX ? 0 : mini;
    }
};

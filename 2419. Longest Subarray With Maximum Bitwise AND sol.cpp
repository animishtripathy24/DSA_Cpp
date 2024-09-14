class Solution {
public:
    //longest subarray with max value
    int longestSubarray(vector<int>& nums) {
        //at first we will find the maximum element in the array
        int maxi = *max_element(begin(nums),end(nums));
        int res = 0;
        int count = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] >= maxi)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            res = max(res,count);
        }
        return res;
    }
};

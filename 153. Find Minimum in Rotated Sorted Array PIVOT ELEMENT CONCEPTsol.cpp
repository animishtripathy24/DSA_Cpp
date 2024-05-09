class Solution {
private:
    int getPivot(vector<int>A,int low,int high)
    {
        while(low < high)
        {
            int mid=low+((high-low)>>1);
            if(A[mid]>=A[0])
            {
                //means it lies on the first line
                low=mid+1;
            }
            else
            {
                //it must lie on the second line
                high=mid;
            }
        }
        return low;
    }
public:
    int findMin(vector<int>& nums) {
        int pivot = getPivot(nums,0,nums.size()-1);
        if(nums[pivot]==nums[nums.size()-1] && nums[nums.size()-1]>nums[0])
        {
            return nums[0];
        }
        return nums[pivot];
    }
};

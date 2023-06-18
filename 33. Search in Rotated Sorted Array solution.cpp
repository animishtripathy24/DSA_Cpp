class Solution {
public:
    int getPivot(vector<int>&nums)
    {
        int start=0;
        int end=nums.size()-1;

        while(start<end)
        {
            int mid=start+(end-start)/2;

            if(nums[mid]>=nums[0])
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }
        return start;
    }
    int binarySearch(vector<int>&nums,int s,int e,int target)
    {
        int start=s;
        int end=e;
        while(start<=end)
        {
            int mid=start+((end-start)/2);

            if(nums[mid]==target)
            {
                return mid;
            }
            else if(target>nums[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot=getPivot(nums);
        int n=nums.size(); 
        if(target>=nums[pivot] && target<=nums[n-1])
        {//target lies on the second line
            return binarySearch(nums,pivot,n-1,target);
        }
        //target lies on the first line
        return binarySearch(nums,0,pivot-1,target);
    }
};

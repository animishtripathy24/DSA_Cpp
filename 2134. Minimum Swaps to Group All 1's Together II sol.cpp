class Solution {
private:
    int countOnes(vector<int>&nums)
    {
        int count = 0;
        for(auto &it : nums)
        {
            if(it & 1)
            {
                count++;
            }
        }
        return count;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        //at first we have to count the number of ones
        int totalOnes = countOnes(nums);
        //now we have to append the same array in itself to get rid of circular array
        vector<int>ans(2*n);
        for(int i=0;i<2*n;i++)
        {
            ans[i]=nums[i%n];
        }
        //the size of the window is the count of total number of ones
        int k = totalOnes;
        int i=0;
        int j=0;
        int mini = INT_MAX;
        int size = 2*n;
        int currOnes = 0;
        while(j<size)
        {
            if(ans[j] & 1)
            {
                currOnes++;
            }
            if(j-i+1 < k)
            {
                j++;
            }
            else
            {
                mini= min(mini,(totalOnes - currOnes));
                if(ans[i] & 1)
                {
                    currOnes--;
                }
                i++;
                j++;
            }
        }
        return mini;
    }
};

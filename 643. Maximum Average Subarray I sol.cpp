class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size() ==1 && k==1)
        {
            return (double)nums[0]/1.0;
        }
        double maxi = numeric_limits<double>::lowest();
        int i = 0;
        int j = 0;
        int size = nums.size();
        int sum = 0;
        while(j < size)
        {
            sum+=nums[j];
            if(j-i+1 < k)
            {
                j++;
            }
            else
            {
                double avg = ((double)sum / (double)k);
                maxi = max(maxi,avg);
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};

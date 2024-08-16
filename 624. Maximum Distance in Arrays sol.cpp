class Solution {
public:
    int maxDistance(vector<vector<int>>& nums) {
        int mini = *min_element(begin(nums[0]),end(nums[0]));
        int maxi = *max_element(begin(nums[0]),end(nums[0]));
        int n = nums.size();
        int res = INT_MIN;
        for(int i = 1 ; i < n ; i++)
        {
            int currMini = *min_element(begin(nums[i]),end(nums[i]));
            int currMaxi = *max_element(begin(nums[i]),end(nums[i]));
            res = max(res , abs(currMini-maxi));
            res = max(res , abs(currMaxi-mini));
            mini = min(mini,currMini);
            maxi = max(maxi,currMaxi);
        }
        return res;
    }
};

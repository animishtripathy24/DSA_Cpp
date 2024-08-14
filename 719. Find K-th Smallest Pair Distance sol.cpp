class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(begin(nums),end(nums));
        vector<int>ans(maxi+1,0);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int diff = abs(nums[i]-nums[j]);
                ans[diff]++;
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            k-=ans[i];
            if(k<=0)
            {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>s;
        int i=0;
        int j=0;
        vector<int>ans;
        while(j<nums.size())
        {
            s.insert(nums[j]);
            if(j-i+1 < k)
            {
                j++;
            }
            else
            {
                int currMax = *s.rbegin();
                ans.push_back(currMax);
                s.erase(s.find(nums[i]));
                i++;
                j++;

            }
        }
        return ans;
    }
};

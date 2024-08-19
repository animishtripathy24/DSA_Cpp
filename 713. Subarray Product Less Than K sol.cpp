class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int size = nums.size();
        int product = 1;
        int count = 0;
        while(j < size)
        {
            product = product * nums[j];
            while(product >= k && i <= j)
            {
                // cout << "NO" << endl;
                product = product / nums[i];
                i++;
            }
            if(product < k) count+=(j-i+1);
            j++;
        }
        return count;
    }
};

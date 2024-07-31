class Solution {
public:
    bool static cmp(int a ,int b)
    {
        return (a&1) < (b&1);
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(begin(nums),end(nums),cmp);
        return nums;
    }
};

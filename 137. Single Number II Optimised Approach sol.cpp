class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //we have to check each and every bit
        int res = 0;
        for(int i=0;i<=31;i++)
        {
            int countZeros = 0;
            int countOnes = 0;
            for(auto &value : nums)
            {
                if(value & (1<<i))
                {
                    countOnes++;
                }
                else
                {
                    countZeros++;
                }
            }
            if(countOnes % 3 == 1)
            {
                res = (res | (1<<i));
            }
        }
        return res;
    }
};

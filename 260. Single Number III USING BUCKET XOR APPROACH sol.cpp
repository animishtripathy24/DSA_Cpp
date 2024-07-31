class Solution {
private:
    int getBit(int xori)
    {
        int count = 0;
        while(xori != 0)
        {
            if((xori & 1) == 0)
            {
                count++;
            }
            else
            {
                break;
            }
            xori = xori >> 1;
        }
        return count;
    }
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xori = 0;
        for(int i=0;i<nums.size();i++)
        {
            xori = xori ^ nums[i];
        }
        int rightmostSetBit = getBit(xori);
        int bitMask = (1 << rightmostSetBit);
        int b1 = 0;
        int b2 = 0; 
        for(int i=0;i<nums.size();i++)
        {
            if(bitMask & nums[i])
            {
                //it means that the rightmost bit is set and we have to put it in bucket1
                b1 = b1 ^ nums[i];
            }
            else
            {
                b2 = b2 ^ nums[i];
            }
        } 
        return {b1,b2};
    }
};

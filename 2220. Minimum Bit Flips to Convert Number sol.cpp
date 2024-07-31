class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xori = start ^ goal;
        int count = 0;
        while(xori != 0)
        {
            if(xori & 1)
            {
                count++;
            }
            xori = xori >> 1;
        }
        return count;
    }
};

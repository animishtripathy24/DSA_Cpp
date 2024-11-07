class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi = INT_MIN;
        for(int bitPos = 0 ; bitPos < 32 ; bitPos++)
        {
            int count = 0;
            for(auto &num:candidates)
            {
                if(num & (1<<bitPos))
                {
                    count++;
                }
            }
            maxi = max(maxi , count);
        }
        return maxi;
    }

};

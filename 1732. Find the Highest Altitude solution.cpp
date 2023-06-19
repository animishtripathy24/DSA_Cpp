class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxHeight=0;
        int gainAltitude=0;
        for(int i=0;i<gain.size();i++)
        {
            gainAltitude+=gain[i];
            maxHeight=max(maxHeight,gainAltitude);
        }

        return maxHeight;
        
    }
};

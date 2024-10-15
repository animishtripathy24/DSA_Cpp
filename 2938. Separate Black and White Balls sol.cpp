class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps = 0LL;
        long long count_black = 0LL;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '1')
            {
                count_black++;
            }
            else
            {
                swaps += count_black;
            }
        }
        return swaps;
    }
};

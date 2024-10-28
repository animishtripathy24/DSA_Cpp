class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> s(nums.begin(), nums.end());
        int maxi = INT_MIN;

        for (auto it = s.begin(); it != s.end();) {
            long long value = *it;
            if (value > 320) {
                break;
            }

            int count = 1;
            long long x = value;

            while (s.find(x * x) != s.end()) {
                s.erase(x);
                x = x * x;
                count++;
            }
            s.erase(x);
            maxi = max(maxi, count);
            it = s.begin();
        }

        return (maxi < 2) ? -1 : maxi;
    }
};

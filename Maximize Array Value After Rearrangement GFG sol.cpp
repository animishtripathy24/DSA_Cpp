class Solution {
public:
    int Maximize(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long long sum = 0;
        long long mod = 1e9 + 7;
        
        for(int i = 0; i < arr.size(); i++) {
            sum = (sum + (arr[i] * 1LL * i) % mod) % mod;
        }
        
        return (int)sum;
    }
};


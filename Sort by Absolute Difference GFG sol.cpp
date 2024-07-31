class Solution {
  public:
    void sortABS(int k, vector<int> &arr) {
        auto cmp = [k](int a, int b) 
        {
            return abs(a - k) < abs(b - k);
        };
        stable_sort(begin(arr),end(arr),cmp);
    }
};

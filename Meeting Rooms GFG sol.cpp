class Solution {
  private:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1] < b[1];
    }
  public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(),arr.end(),cmp);
        for (int i = 1; i < arr.size(); ++i) {
            // Check if current meeting overlaps with the previous one
            if (arr[i][0] < arr[i - 1][1]) {
                return false;
            }
        }
        return 1;
    }
};

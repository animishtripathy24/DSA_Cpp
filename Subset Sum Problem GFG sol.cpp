class Solution {
  private:
    bool solve(vector<int>& arr, int n, int sum, vector<vector<int>>& t)
    {
        if (sum == 0)
        {
            return true; 
        }
        if (n == 0 || sum < 0)
        {
            return false; 
        }
        if (t[n][sum] != -1)
        {
            return t[n][sum];
        }

        if (arr[n-1] <= sum)
        {
            t[n][sum] = (solve(arr, n-1, sum-arr[n-1], t) || solve(arr, n-1, sum, t));
            return t[n][sum];
        }
        else
        {
            t[n][sum] = solve(arr, n-1, sum, t);
            return t[n][sum];
        }
    }

  public:
    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size();
        vector<vector<int>> t(n+1, vector<int>(sum+1, -1));
        return solve(arr, n, sum, t);
    }
};

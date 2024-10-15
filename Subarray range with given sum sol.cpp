class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int,int>m; //stores {element,count}
        m[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            int remain = sum - tar;
            count+=m[remain];
            m[sum]++;
        }
        return count;
    }
};

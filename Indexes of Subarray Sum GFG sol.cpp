class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        int i=0;
        int j=0;
        long long sum =0;
        while(j < n)
        {
            sum+=arr[j];
            if(sum < s)
            {
                j++;
            }
            else if(sum > s)
            {
                while(sum > s && i<j)
                {
                    sum-=arr[i];
                    i++;
                    if(sum == s)
                    {
                        return {i+1,j+1};
                    }
                }
                j++;
            }
            else
            {
                return {i+1,j+1};
            }
        }
        return {-1};
    }
};

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int sum = 0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
        }
        if(sum & 1)
        {
            return 0;
        }
        int prefixSum = 0;
        for(int i=0;i<arr.size();i++)
        {
            prefixSum+=arr[i];
            if(prefixSum == (sum/2))
            {
                return 1;
            }
        }
        return 0;
        
    }
};

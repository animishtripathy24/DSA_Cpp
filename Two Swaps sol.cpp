class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        int swapCount = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] != i+1)
            {
                swap(arr[i],arr[arr[i]-1]);
                swapCount++;
                i--;
            }
            if(swapCount>2)
            {
                return 0;
            }
        }
        return swapCount == 0 || swapCount == 2;
    }
};

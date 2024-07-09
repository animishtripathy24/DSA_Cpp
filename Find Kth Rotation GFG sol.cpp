class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        if(arr[0]<arr[arr.size()-1])
        {
            return 0;
        }
        //we have to find the pivot index in the array
        int low = 0;
        int high = arr.size()-1;
        while(low < high)
        {
            int mid = low+((high-low)>>1);
            if(arr[mid]>=arr[0])
            {
                //it means that it lies in the first line
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }
        return high;
    }
};

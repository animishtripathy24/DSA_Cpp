class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        if(arr[low] < arr[high])
        {
            return arr[0];
        }
        //basically we have to find the pivot index
        while( low < high)
        {
            int mid = low+((high - low)>>1);
            if(arr[mid]>=arr[0])
            {
                //it means it lies on the first line
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }
        return arr[high];
        
    }
};

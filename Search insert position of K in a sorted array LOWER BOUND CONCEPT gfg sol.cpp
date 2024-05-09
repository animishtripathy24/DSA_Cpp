class Solution{
    private:
    int lowerBound(vector<int>&arr,int low,int high,int k,int index)
    {
        //base case
        if(low > high)
        {
            return index;
        }
        //at first we have to find the middle element in the array
        int mid=low+((high-low)>>1);
        if(arr[mid]>=k)
        {
            index=mid;
            return lowerBound(arr,low,mid-1,k,index);
        }
        return lowerBound(arr,mid+1,high,k,index);
    }
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        int index=N;
        return lowerBound(Arr,0,N-1,k,index);
    }
};

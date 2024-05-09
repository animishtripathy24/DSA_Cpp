class Solution {
  private:
    int getPivot(int A[],int low,int high)
    {
        while(low < high)
        {
            int mid=low+((high-low)>>1);
            if(A[mid]>=A[0])
            {
                //means it lies on the first line
                low=mid+1;
            }
            else
            {
                //it must lie on the second line
                high=mid;
            }
        }
        return low;
    }
    int binarySearch(int a[],int s,int e,int key)
    {
        int start=s;
        int end=e;
    
        while(start<=end)
        {
            int mid=start+(end-start)/2;//to neglect integer overflow.
    
            if(a[mid]==key)
            {
                return mid;
            }
            else if(key>a[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return -1;
    }
  public:
    int search(int A[], int l, int h, int key) {
        //at first we have to find the pivot element
        int pivot=getPivot(A,l,h);
        
        //now we have to check whether our key lies on the first line or in the second line
        if(key >= A[pivot] && key <= A[h])
        {
            return binarySearch(A,pivot,h,key);
        }
        //it must lie on the first line
        return binarySearch(A,l,pivot-1,key);
    }
};

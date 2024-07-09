class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    int low = 0;
	    int high = n-1;
	    
	    while(low < high)
	    {
	        int mid = low+((high-low)>>1);
	        if(arr[mid]<arr[mid+1])
	        {
	            //it means it lies on the first line
	            low = mid + 1;
	        }
	        else
	        {
	            //it means it lies on the second line
	            high = mid;
	        }
	    }
	    return arr[low];
	}
};

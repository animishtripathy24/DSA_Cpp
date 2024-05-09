//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    if(N==1)
	    {
	        return A[0];
	    }
	    if(A[0] != A[1])
	    {
	        return A[0];
	    }
	    if(A[N-1] != A[N-2])
	    {
	        return A[N-1];
	    }
	    //now we have to apply binary search on the remaining elements
	    int low=1;
	    int high=N-2;
	    while(low <= high)
	    {
	        int mid = low + ((high - low ) >> 1);
	        if(A[mid]!= A[mid+1] && A[mid]!=A[mid-1])
	        {
	            return A[mid];
	        }
	        else if(((mid & 1) && A[mid-1]==A[mid]) || (((mid & 1) ==0) && A[mid+1]==A[mid]))
	        {
	            //left part
	            low=mid+1;
	        }
	        else
	        {
	            high=mid-1;
	        }
	    }
	    return -1;
	}
};

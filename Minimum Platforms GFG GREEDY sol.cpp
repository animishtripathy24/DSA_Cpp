class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	//we are concerned only with the timings so we will sort 
    	//it to give everything according to timings
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0;
    	int j=0;
    	int count =0;
    	int maxPlatforms = 0;
    	while(i<n && j<n)
    	{
    	    if(arr[i]<=dep[j])
    	    {
    	        count++;
    	        i++;
    	    }
    	    else
    	    {
    	        count--;
    	        j++;
    	    }
    	    maxPlatforms = max(maxPlatforms,count);
    	}
    	return maxPlatforms;
    }
};

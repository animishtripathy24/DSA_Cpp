class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int>m;
	    m[0]=-1;
	    int sum = 0;
	    int maxi = 0;
	    for(int i=0;i<n;i++)
	    {
	        sum += arr[i];
	        int rem = sum % k;
	        if(rem < 0)
	        {
	            rem+=k;
	        }
	        if(rem == 0)
	        {
	            maxi = max(maxi,i+1);
	        }
	        if(m.find(rem) != m.end())
	        {
	            maxi = max(maxi , i-m[rem]);
	        }
	        else
	        {
	            m[rem]=i;
	        }
	    }
	    return maxi;
	}
};

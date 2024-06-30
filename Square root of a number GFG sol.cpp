// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int low=1;
        long long int high=x;
        long long int ans=-1;
        while(low <=high)
        {
            long long int mid=low+((high-low)>>1);
            if(mid * mid == x)
            {
                ans=mid;
                return ans;
            }
            else if(mid * mid < x)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};

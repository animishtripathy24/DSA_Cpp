class Solution{
  private:
    long long solve(vector<long long>v,long long low,long long high,long long x,long long &floor)
    {
        if(low > high)
        {
            return floor;
        }
        //at first we have to find the mid element
        long long mid=low+((high-low)>>1);
        if(v[mid]<=x)
        {
            floor=mid;
            return solve(v,mid+1,high,x,floor);
        }
        return solve(v,low,mid-1,x,floor);
    }
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        long long floor=-1;
        return (int)solve(v,0,n-1,x,floor);
        
    }
};

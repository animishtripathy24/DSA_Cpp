class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long>>mini;
        
        for(int i=0;i<n;i++)
        {
            mini.push(arr[i]);
        }
        long long sum=0;
        while(mini.size()>1)
        {
            long long a=mini.top();
            mini.pop();
            long long b=mini.top();
            mini.pop();
            sum+=(a+b);
            mini.push(a+b);
        }
        return sum;
    }
};

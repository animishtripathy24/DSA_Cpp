class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        if(n==1)
        {
            return arr[0];
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        long long first=0LL;
        long long second=0LL;
        while(pq.size()!=1 && pq.size()!=0)
        {
            int a=pq.top();
            pq.pop();
            first=(first*10)+a;
            int b=pq.top();
            pq.pop();
            second=(second*10)+b;
        }
        if(!pq.empty())
        {
           first=(first*10)+pq.top();
            pq.pop();
        }
        return (first+second);
    }
};

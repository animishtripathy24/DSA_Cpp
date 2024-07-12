class Solution{
    private:
    long long getKSmallest(long long A[],long long N,long long k)
    {
        //at first we have to declare a max heap
        priority_queue<long long>pq;
        for(long long int i=0;i<N;i++)
        {
            if(pq.size() < k)
            {
                pq.push(A[i]);
            }
            else 
            {
                if(A[i] < pq.top())
                {
                    pq.pop();
                    pq.push(A[i]);
                }
            }
        }
        return pq.top();
    }
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        long long x = getKSmallest(A,N,K1);
        long long y = getKSmallest(A,N,K2);
        long long sum = 0;
        for(long long int i=0;i<N;i++)
        {
            if(A[i] > x && A[i] < y)
            {
                sum+=A[i];
            }
        }
        return sum;
    }
};

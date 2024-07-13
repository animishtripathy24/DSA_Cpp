vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K){
        vector<long long>ans;
        deque<long long>dq;
        long long i=0;
        long long j=0;
        while(j < N)
        {
            if(A[j] < 0)
            {
                dq.push_back(A[j]);
            }
            if(j-i+1 < K)
            {
                j++;
            }
            else
            {
                if(dq.empty())
                {
                    ans.push_back(0LL);
                }
                else
                {
                    ans.push_back(dq.front());
                }
                if(A[i] < 0)
                {
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
 }

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        //at first we have to declare a unordered_map to store the remaining sum
        unordered_map<int,int>m;
        
        int len=0;
        int sum=0;
        
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum==K)
            {
                len=max(len,i+1);
            }
            int rem=sum-K;
            if(m.find(rem) != m.end())
            {
                int length=i-m[rem];
                len=max(len,length);
            }
            if(m.find(sum)==m.end())
            {
                m[sum]=i;
            }
        }
        return len;
    } 

};

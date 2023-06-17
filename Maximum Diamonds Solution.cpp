class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        //creating a max heap
        priority_queue<int>maxi;
        for(int i=0;i<N;i++)
        {
            maxi.push(A[i]);
        }
        long long sum=0;
        for(int i=0;i<K;i++)
        {
            int x=maxi.top();
            sum+=x;
            maxi.pop();
            maxi.push(x/2);
        }
        
        return sum;
    }
};

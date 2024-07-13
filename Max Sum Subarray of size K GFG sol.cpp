class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long int sum = 0;
        long int maxi = LONG_MIN;
        int i=0;
        int j=0;
        while(j<N)
        {
            sum+=Arr[j];
            if(j-i+1 < K)
            {
                j++;
            }
            else
            {
                maxi = max(maxi,sum);
                sum-=Arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};

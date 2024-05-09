class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        //at first we have to sort the vector
        sort(happiness.rbegin(),happiness.rend());
        long long sum=0LL;
        for(int i=0;i<k;i++)
        {
            long long ans=max(0,happiness[i]-i);
            sum+=ans;
        }
        return sum;

    }
};

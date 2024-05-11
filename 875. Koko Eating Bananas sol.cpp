class Solution {
private:
    long long func(vector<int>&piles,int mid)
    {
        long long totalHours=0LL; 
        for(int i=0;i<piles.size();i++)
        {
            totalHours += ceil((double)(piles[i]) / (double)(mid));
        }
        return totalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //applying binary search technique
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low <= high)
        {
            int mid=low+((high-low)>>1);
            long long int requiredTime=func(piles,mid);
            if(requiredTime<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};

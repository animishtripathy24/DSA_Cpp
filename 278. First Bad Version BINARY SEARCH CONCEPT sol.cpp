// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1;
        int high=n;
        int ans = -1;
        while(low <= high)
        {
            int mid=low+((high-low)>>1);
            if(isBadVersion(mid))
            {
                ans=mid;
                high=mid-1;
            }
            else if(!isBadVersion(mid))
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};

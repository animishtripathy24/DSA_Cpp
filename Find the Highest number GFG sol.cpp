class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int low=0;
        int high=a.size()-1;
        
        while(low < high)
        {
            int mid=low+((high-low)>>1);
            if(a[mid]<a[mid+1])
            {
                //this means it lies on the first line
                low=mid+1;
            }
            else
            {
                //it must lie on the second line
                high=mid;
            }
        }
        return a[high];
    }
};

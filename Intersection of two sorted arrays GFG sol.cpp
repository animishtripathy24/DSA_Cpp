class Solution {
  public:
    // Function to return a list containing the intersection of two arrays.
    vector<int> printIntersection(vector<int> &arr1, vector<int> &arr2) {
        //at first we will figure out the size of botn the arrays
        int n = arr1.size();
        int m = arr2.size();
        vector<int>interArr;
        int i = 0;
        int j = 0;
        while(i < n && j < m)
        {
            if(arr1[i] < arr2[j])
            {
                i++;
            }
            else if(arr1[i] > arr2[j])
            {
                j++;
            }
            else
            {
                //just take this into the array
                if(interArr.empty() || interArr.back() != arr1[i])
                {
                    interArr.push_back(arr1[i]);
                }
                i++;
                j++;
            }
        }
        if(interArr.size() == 0)
        {
            return {-1};
        }
        return interArr;
        
    }
};

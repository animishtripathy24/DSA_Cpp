class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        int maxi = 0;
        int count = 0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr.at(i) > arr.at(i-1))
            {
                count++;
                maxi = max(maxi,count);
            }
            else
            {
                count = 0;
            }
        }
        return maxi;
    }
};

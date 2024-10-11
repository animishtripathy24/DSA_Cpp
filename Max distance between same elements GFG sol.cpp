class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int,int>firstOccu;
        unordered_map<int,int>lastOccu;
        for(int i=0;i<arr.size();i++)
        {
            if(firstOccu.find(arr[i]) == firstOccu.end())
            {
                firstOccu[arr[i]] = i;
            }
            lastOccu[arr[i]] = i;
        }
        int maxi = INT_MIN;
        for(auto &it : firstOccu)
        {
            maxi = max(maxi,(lastOccu[it.first] - it.second));
        }
        return maxi;
    }
};

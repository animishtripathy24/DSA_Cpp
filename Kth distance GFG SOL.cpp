class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++)
        {
            if(m.find(arr[i]) == m.end())
            {
                m[arr[i]] = i;
            }
            else
            {
                if(i-m[arr[i]]<=k)
                {
                    return 1;
                }
                else
                {
                    m[arr[i]] = i;
                }
            }
        }
        return 0;
    }
    
};

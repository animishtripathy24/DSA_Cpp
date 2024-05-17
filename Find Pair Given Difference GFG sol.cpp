class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(m.find(x+arr[i]) != m.end() && m[x+arr[i]]!= i)
            {
                return 1;
            }
        }
        return -1;
        
    }
};

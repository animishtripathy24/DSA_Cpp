class Solution {
  public:
    int firstElement(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (m[arr[i]] == k) {
                return arr[i];
            }
        }
        
        return -1;
    }
};

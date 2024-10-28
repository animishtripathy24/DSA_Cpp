class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        vector<int>vis(101,-1);
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            if(vis[arr[i]] == -1)
            {
                ans.push_back(arr[i]);
            }
            vis[arr[i]] = 0;
        }
        return ans;
    }
};

class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        //at first we have to sort the array 
        sort(b.begin(),b.end());
        vector<int>ans;
        for(int i=0;i<query.size();i++)
        {
            int num_of_ele=upper_bound(b.begin(),b.end(),a[query[i]])-b.begin();
            ans.push_back(num_of_ele);
        }
        return ans;
    }
};

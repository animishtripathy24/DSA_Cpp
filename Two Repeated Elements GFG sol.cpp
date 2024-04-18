class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        //at first we wiil declare a unoredred_map
        unordered_map<int,bool>m;
        vector<int>ans;
        for(int i=0;i<n+2;i++)
        {
            auto it=m.find(arr[i]);
            if(it==m.end())
            {
                m.insert({arr[i],true});
            }
            else
            {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};

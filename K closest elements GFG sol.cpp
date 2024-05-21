class Solution {
  private:
    static bool cmp(pair<int,int>a,pair<int,int>b)
    {
        if(a.first != b.first)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        //at first we have to take a max heap
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++)
        {
             ans.push_back({abs(arr[i]-x),arr[i]});
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int>res;
        int i=0;
        while(i<ans.size() && k--)
        {
            if(ans[i].second == x)
            {
                i++;
                k=k+1;
                continue;
            }
            if(!res.empty() && res.back()==ans[i].second)
            {
                continue;
            }
            res.push_back(ans[i].second);
            i++;
        }
        return res;
    }
};

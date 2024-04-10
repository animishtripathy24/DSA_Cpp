class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int>s;
        s.push(0);
        for(int i=1;i<arr.size();i++)
        {
            if(!s.empty() && ((arr[i]>=0 && arr[s.top()]<0) || (arr[i]<0 && arr[s.top()]>=0)))
            {
                s.pop();
            }
            else
            {
                s.push(i);
            }
        }
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(arr[s.top()]);
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

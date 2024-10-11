class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        int n = arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==-1)
            {
                continue;
            }
            pq.push(arr[i]);
        }
        int index = 0;
        vector<int>ans;
        while(index < n && !pq.empty())
        {
            if(index == pq.top())
            {
                ans.push_back(pq.top());
                pq.pop();
            }
            else
            {
                ans.push_back(-1);
            }
            index++;
        }
        while(index < n)
        {
            ans.push_back(-1);
            index++;
        }
        return ans;
    }
};

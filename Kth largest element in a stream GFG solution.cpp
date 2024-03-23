class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int>ans;
        for(int i=0;i<k-1;i++)
        {
            ans.push_back(-1);
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        //at first insert the first k elements in the queue
        for(int i=0;i<k;i++)
        {
            pq.push(arr[i]);
        }
        for(int i=k;i<n;i++)
        {
            ans.push_back(pq.top());
            if(arr[i]>pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        ans.push_back(pq.top());
        return ans;
    }
};

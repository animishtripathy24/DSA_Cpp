class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        //at first we have to declare a priority queue
        deque<int>dq;
        int i=0;
        int j=0;
        int n = arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!dq.empty() && dq.front() == i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()] < arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1)
            {
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};

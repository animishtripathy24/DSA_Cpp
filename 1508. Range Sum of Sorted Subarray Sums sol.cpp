class Solution {
public:
    int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        //at first we have to declare a min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //{subarray sum , end index of the subarray}
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }

        int res = 0;
        int count = 1;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int sum = it.first;
            int index = it.second;

            if(count >= left && count <= right)
            {
                res= (res + sum ) % MOD;
            }
            if(index+1 < n)
            {
                pq.push({sum+nums[index+1],index+1});
            }
            count++;
        }
        return res;

    }
};

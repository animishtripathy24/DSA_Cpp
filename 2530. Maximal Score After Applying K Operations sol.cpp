class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0LL;
        priority_queue<int>pq;
        for(auto &it : nums)
        {
            pq.push(it);
        }
        while(!pq.empty() && k--)
        {
            score+=pq.top();
            int element = ceil((double)pq.top()/3.0);
            pq.pop();
            pq.push(element);
        }
        return score;
    }
};

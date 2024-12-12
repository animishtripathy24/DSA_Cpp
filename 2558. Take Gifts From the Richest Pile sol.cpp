class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int i=0;i<gifts.size();i++)
        {
            pq.push(gifts[i]);
        }
        int count = 0;
        long long total = 0LL;
        while(!pq.empty() && k--)
        {
            int top = pq.top();
            pq.pop();
            total += sqrt(top);
            top = sqrt(top);
            pq.push(top);
        }
        long long remaining = 0LL;
        while(!pq.empty())
        {
            remaining += pq.top();
            pq.pop();
        }
        return remaining;
    }
};

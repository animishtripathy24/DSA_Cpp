class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        //at first we have to sort thr array
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(!pq.empty() && intervals[i][0]>pq.top())
            {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};

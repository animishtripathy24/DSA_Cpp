class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //we have to declare a max heap
        priority_queue<pair<float,vector<int>>>pq;
        for(auto &it : points)
        {
            int a = it[0];
            int b = it[1];
            float dist = sqrt(pow((a-0),2)+pow((b-0),2));
            if(pq.size() < k)
            {
                pq.push({dist,{{a,b}}});
            }
            else if(dist < pq.top().first)
            {
                pq.pop();
                pq.push({dist,{{a,b}}});
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

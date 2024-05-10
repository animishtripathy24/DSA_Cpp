class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        //we have to declare a min heap
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                pq.push({(double)(arr[i]/(double)arr[j]),{arr[i],arr[j]}});
            }
        }
        while(!pq.empty() && --k)
        {
            auto it=pq.top();
            pq.pop();
            // cout << it.first << " " << it.second.first << " " << it.second.second << endl;
        }
        return {pq.top().second.first,pq.top().second.second};

    }
};

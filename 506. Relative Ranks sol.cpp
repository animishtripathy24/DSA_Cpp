class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        //at first we have to make a priority queue {max heap}
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++)
        {
            pq.push({score[i],i});
        }
        vector<string>ans(score.size());
        int k=1;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int index=it.second;
            if(k==1)
            {
                ans[index]="Gold Medal";
            }
            else if(k==2)
            {
                ans[index]="Silver Medal";
            }
            else if(k==3)
            {
                ans[index]="Bronze Medal";
            }
            else
            {
                ans[index]=to_string(k);
            }
            k++;
        } 
        return ans;

    }
};

class Solution
{
    private:
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        // if(a.first == b.first)
        // {
        //     return a.second < b.second;
        // }
        return a.second < b.second;
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        //at first we have to initialize 
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back({start[i],end[i]});
        }
        //then we have to think greedily and sort the ans
        //according to the end time
        sort(ans.begin(),ans.end(),cmp);
        vector<pair<int,int>>res;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(res.empty() || ans[i].first > res.back().second)
            {
                res.push_back(ans[i]);
            }
            else
            {
                count++;
            }
        }
        return n-count;
    }
};

class Solution{
    bool static cmp(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b)
    {
        if(a.first.first == b.first.first)
        {
            return a.first.second < b.first.second;
        }
        return a.first.second < b.first.second;
    }
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<pair<int,int>,int>>ans;
        for(int i=0;i<N;i++)
        {
            ans.push_back({{S[i],F[i]},i});
        }
        sort(begin(ans),end(ans),cmp);
        // for(auto &it:ans)
        // {
        //     // cout << it.first.first << " " << it.first.second << it.second << endl;
        // }
        // return {};
        vector<pair<pair<int,int>,int>>intervals;
        for(int i=0;i<ans.size();i++)
        {
            if(intervals.empty() || ans[i].first.first > intervals.back().first.second)
            {
                intervals.push_back(ans[i]);
            }
            else
            {
                continue;
            }
        }
        vector<int>res;
        for(auto &it:intervals)
        {
            res.push_back(it.second+1);
        }
        sort(res.begin(),res.end());
        return res;
    }
};

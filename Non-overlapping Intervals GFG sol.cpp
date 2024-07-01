class Solution {
  private:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1] < b[1];
    }
  public:
    int minRemoval(int N, vector<vector<int>> &intervals) {
        //at first we will sort the array
        sort(intervals.begin(),intervals.end(),cmp);
        // for(auto &it: intervals)
        // {
        //     for(auto &itt:it)
        //     {
        //         cout << itt << " ";
        //     }
        //     cout << endl;
        // }
        vector<vector<int>>ans;
        int count=0;
        for(int i=0;i<N;i++)
        {
            if(ans.empty() || intervals[i][0] >= ans.back()[1])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};

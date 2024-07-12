class Solution {
static bool cmp(pair<int,int>&a,pair<int,int>&b)
{
    if(a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
public:
    vector<int> frequencySort(vector<int>& nums) {
        //at first we have to hash the numbers
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        //now we will declare a min heap
        vector<pair<int,int>>v;
        for(auto &it:m)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<v.size();i++)
        {
            int top = v[i].first;
            cout << top << " ";
            for(int j=0;j<top;j++)
            {
                ans.push_back(v[i].second);
            }
        }
        return ans;
    }
};

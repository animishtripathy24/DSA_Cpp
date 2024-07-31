class Solution {
private:
    int getBits(int n)
    {
        int count = 0;
        while(n != 0)
        {
            if(n & 1)
            {
                count++;
            }
            n= n >> 1;
        }
        return count;
    }
public:
    bool static cmp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>ans;
        for(auto &value:arr)
        {
            ans.push_back({value,getBits(value)});
        }
        sort(begin(ans),end(ans),cmp);
        vector<int>res;
        for(auto &value:ans)
        {
            res.push_back(value.first);
        }
        return res;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        //creating a max heap
        priority_queue<pair<int,char>>maxi;

        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }

        for(auto &value:m)
        {
            maxi.push({value.second,value.first});
        }
        string ans;
        while(!maxi.empty())
        {
            auto it= maxi.top();
            maxi.pop();

            for(int i=0;i<it.first;i++)
            {
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>m;
        int i=0;
        int j=0;
        while(j < s.size())
        {
            if(j-i+1 < 10)
            {
                j++;
            }
            else
            {
                string temp = s.substr(i,j-i+1);
                m[temp]++;
                i++;
                j++;
            }
        }
        vector<string>ans;
        for(auto &it:m)
        {
            if(it.second > 1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

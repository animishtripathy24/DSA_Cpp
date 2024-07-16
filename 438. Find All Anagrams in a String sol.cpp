class Solution {
private:
    bool allZeroes(unordered_map<char,int>&m)
    {
        for(auto &it:m)
        {
            if(it.second != 0)
            {
                return 0;
            }
        }
        return 1;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>m;
        for(int i=0;i<p.size();i++)
        {
            m[p[i]]++;
        }
        int k = p.size();
        int i=0;
        int j=0;
        vector<int>ans;
        while( j < s.size())
        {
            m[s[j]]--;
            if(j-i+1 < k)
            {
                j++;
            }
            else
            {
                if(allZeroes(m))
                {
                    ans.push_back(i);
                }
                m[s[i]]++;
                i++;
                j++;
            }
        } 
        return ans; 
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }
        int i=0;
        int j = 0;
        int minLen = INT_MAX;
        int startingIndex = -1;
        int n = s.size();
        int m = t.size();
        int count = 0;
        while(j<n)
        {
            if(mp[s[j]]>0)
            {
                count=count+1;
            }
            mp[s[j]]--;

            while(count == m)
            {
                int sizeOfWindow = j-i+1;
                if(sizeOfWindow < minLen)
                {
                    minLen = sizeOfWindow;
                    startingIndex = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                {
                    count = count - 1;
                }
                i++;
            }

            j++;
        }

        return startingIndex == -1 ? "" : s.substr(startingIndex , minLen);
    }
};

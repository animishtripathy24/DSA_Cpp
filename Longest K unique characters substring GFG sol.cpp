class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int>m;
        int i=0;
        int j=0;
        int maxi = INT_MIN;
        while(j<s.size())
        {
            m[s[j]]++;
            if(m.size() < k)
            {
                j++;    
            }
            else if(m.size() > k)
            {
                while(m.size() > k)
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
            else
            {
                int sizeOfWindow =  j-i+1;
                maxi = max(maxi,sizeOfWindow);
                j++;
            }
        }
        return maxi==INT_MIN ? -1 : maxi;
    }
};

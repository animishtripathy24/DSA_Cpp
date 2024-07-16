class Solution {
  public:

    string printString(string s, char ch, int count) {
        int i=0;
        for(;i<s.size();i++)
        {
            if(s[i] == ch)
            {
                count--;
            }
            if(!count)
            {
                break;
            }
        }
        if(i < s.size())
        {
            return s.substr(i+1);
        }
        return "";
    }
};

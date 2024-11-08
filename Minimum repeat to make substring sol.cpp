class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        string str = s1;
        int count = 1;
        while(s1.size() < s2.size())
        {
            s1+=str;
            count++;
        }
        if(s1.find(s2) != -1)
        {
            return count;
        }
        s1+=str;
        count++;
        if(s1.find(s2) != -1)
        {
            return count;
        }
        return -1;
    }
};

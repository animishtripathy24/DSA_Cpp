class Solution {
public:
    string getEncryptedString(string s, int k) {
        string str;
        for(int i=0;i<s.size();i++)
        {
            int newIndex = (i+k) % s.size();
            str.push_back(s[newIndex]);
        }
        return str;
    }
};

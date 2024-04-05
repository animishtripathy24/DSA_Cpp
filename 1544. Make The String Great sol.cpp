class Solution {
public:
    string makeGood(string s) {
        string ans="";
        ans.push_back(s[0]);

        for(int i=1;i<s.size();i++)
        {
            if(!ans.empty() && s[i]!=ans.back() && (s[i]-32==ans.back() || s[i]+32==ans.back()))
            {
                cout << s[i] << " " << ans.back() << endl;
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

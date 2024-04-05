class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && s[i] !=st.top() && ( (s[i]-32==st.top())|| (s[i]+32==st.top()) ))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

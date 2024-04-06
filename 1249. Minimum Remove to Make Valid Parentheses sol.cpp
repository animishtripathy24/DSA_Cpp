class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        vector<int>v;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    v.push_back(i);
                }
                else if(s[st.top()]=='(')
                {
                    st.pop();
                }
            }
        }
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(find(v.begin(),v.end(),i)==v.end())
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
        
    }
};

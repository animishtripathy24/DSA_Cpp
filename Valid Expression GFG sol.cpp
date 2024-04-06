unordered_map<char,int>m={{'(',-3},{'{',-2},{'[',-1},{')',3},{'}',2},{']',1}};
bool valid(string s)
{
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(m[s[i]]<0)
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty())
            {
                return 0;
            }
            char top=st.top();
            st.pop();
            if(m[top]+m[s[i]]!=0)
            {
                return 0;
            }
        }
    }
    if(!st.empty())
    {
        return 0;
    }
    return 1;
}

int countRev (string s)
{
    if(s.size() & 1)
    {
        return -1;
    }
    stack<char>st;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{')
        {
            st.push(s[i]);
        }
        else
        {
            if(!st.empty() && st.top()=='{')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    //abhi hamare pass sirf invalid brackets bacche hai...
    int b=0;//countof opening braces
    int a=0;//count of closing braces
    
    while(!st.empty())
    {
        if(st.top()=='{')
        {
            b++;
        }
        else
        {
            a++;
        }
        st.pop();
    }
    
    int ans=(a+1)/2+(b+1)/2;
    return ans;
}

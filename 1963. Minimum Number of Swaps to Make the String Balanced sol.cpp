class Solution {
public:
    int minSwaps(string str) {
        stack<char>s;
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == '[')
            {
                s.push(str[i]);
            }
            else
            {
                if(s.empty())
                {
                    s.push(str[i]);
                }
                else
                {
                    if(s.top() == '[')
                    {
                        s.pop();
                    }
                    else
                    {
                        s.push(str[i]);
                    }
                }
            }
        }
        if(s.empty())
        {
            return 0;
        }
        int openCount = 0;
        while(!s.empty())
        {
            if(s.top() == '[')
            {
                openCount++;
            }
            s.pop();
        }
        return (openCount + 1) >> 1;
    }
};

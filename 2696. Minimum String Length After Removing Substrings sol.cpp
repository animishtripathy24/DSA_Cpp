class Solution {
public:
    int minLength(string str) {
        stack<char>s;
        for(int i=0;i<str.size();i++)
        {
            if(s.empty() || (str[i] != 'B' && str[i] != 'D'))
            {
                s.push(str[i]);
            }
            else
            {
                if(!s.empty() && ((s.top() == 'A' && str[i] == 'B') || (s.top() == 'C' && str[i] == 'D')))
                {
                    s.pop();
                }
                else
                {
                    s.push(str[i]);
                }
            }
        }
        return s.size();
    }
};

class Solution {
public:
    string removeDuplicates(string str) {
        stack<char>s;
        for(int i=0;i<str.size();i++)
        {
            bool check = false;
            if(!s.empty() && s.top() == str[i])
            {
                s.pop();
            }
            else
            {
                s.push(str[i]);
            }
        }
        string ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};

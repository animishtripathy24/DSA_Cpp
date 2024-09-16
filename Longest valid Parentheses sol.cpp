class Solution {
  public:
    int maxLength(string& str) {
        stack<int>s;
        s.push(-1);
        int maxi = 0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='('){
                s.push(i);
            }
            else
            {
                s.pop();
                if(s.empty())
                {
                    s.push(i);
                }
                else
                {
                    maxi = max(maxi , i-s.top());
                }
            }
        }
        return maxi;
    }
};

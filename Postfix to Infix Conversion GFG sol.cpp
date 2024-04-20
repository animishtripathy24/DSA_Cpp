class Solution {
  public:
    string postToInfix(string exp) {
        stack<string>s;
        string ans;
        for(int i=0;i<exp.size();i++)
        {
            if((exp[i]>=97 && exp[i]<=122) || (exp[i]>=65 && exp[i]<=90))
            {
                string temp(1,exp[i]);
                s.push(temp);
            }
            else
            {
                string a=s.top();
                s.pop();
                string b=s.top();
                s.pop();
                s.push('('+b+exp[i]+a+')');
            }
        }
        if(s.empty())
        {
            return "";
        }
        return s.top();
    }
};

class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack<char>s;
        int count=0;
        for(int i=0;i<S.size();i++)
        {
            while(!s.empty() && s.top()>S[i] && count < K)
            {
                s.pop();
                count++;
            }
            s.push(S[i]);
        }
        while(!s.empty() && count < K)
        {
            s.pop();
            count++;
        }
        string ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans[0]=='0')
        {
            ans.erase(0,1);
        }
        if(ans=="")
        {
            return "0";
        }
        return ans;
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        // if(num.size()==1 && k==1)
        // {
        //     return "0";
        // }
        stack<char>s;
        int count=0;
        for(int i=0;i<num.size();i++)
        {
            while(!s.empty() && (s.top()>num[i]) && count < k)
            {
                s.pop();
                count++;
            }
            s.push(num[i]);

        }
        while(!s.empty() && count < k)
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
        cout << ans << endl;
        while(ans[0]=='0')
        {
            ans.erase(0,1);
        }
        if(ans=="") return "0";
        return ans;
    }
};

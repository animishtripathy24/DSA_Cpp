class Solution {
public:
    string simplifyPath(string path) {
        string token="";
        stack<string>s;
        stringstream ss(path);
        string ans;
        while(getline(ss,token,'/'))
        {
            if(token == "." || token == "")
            {
                continue;
            }
            if(token != "..")
            {
                s.push(token);
            }
            else
            {
                if(!s.empty())
                {
                    s.pop();
                }
            }
        }
        if(s.empty())
        {
            return "/";
        }
        while(!s.empty())
        {
            string temp;
            temp.push_back('/');
            temp+=s.top();
            s.pop();
            ans=temp+ans;
        }
        return ans;
    }
};

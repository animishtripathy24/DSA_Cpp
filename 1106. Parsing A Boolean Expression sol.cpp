class Solution {
private:
char solve(vector<char>&ans,char ch)
{
    if(ans.size()==1 && ch == '!')
    {
        if(ans[0] == 'f')
        {
            return 't';
        }
        else
        {
            return 'f';
        }
    }
    else if(ans.size() == 1 && (ch == '&' || ch == '|'))
    {
        return ans[0];
    }
    else
    {
        if(ch == '|')
        {
            bool check = ans[0]=='f' ? 0 : 1; 
            for(int i=1;i<ans.size();i++)
            {
                if(ans[i] == 'f')
                {
                    check = check | 0;
                }
                else
                {
                    check = check | 1;
                }
            }
            return check == 1 ? 't' : 'f'; 
        }
        else
        {
            bool check = ans[0]=='f' ? 0 : 1; 
            for(int i=1;i<ans.size();i++)
            {
                if(ans[i] == 'f')
                {
                    check = check & 0;
                }
                else
                {
                    check = check & 1;
                }
            }
            return check == 1 ? 't' : 'f'; 
        }
    }
}
public:
    bool parseBoolExpr(string expression) {
        stack<char>s;
        for(int i=0;i<expression.size();i++)
        {
            if(expression[i] == '&' || expression[i] == '|' || expression[i] == '!' || expression[i] == 't' || expression[i] == '(' || expression[i] == 'f')
            {
                s.push(expression[i]);
            }
            else
            {
                if(expression[i] == ')')
                {
                    vector<char>ans;
                    while(!s.empty() && s.top() != '(')
                    {
                        ans.push_back(s.top());
                        s.pop();
                    }
                    // for(auto &it : ans)
                    // {
                    //     cout << it << " ";
                    // }cout << endl;
                    s.pop();
                    char ch = s.top();
                    s.pop();
                    char op = solve(ans,ch);
                    s.push(op);
                    
                }

            }
        }
        return s.top()=='t' ? 1:0; 
    }
};

class Solution {
private:
    vector<int> solve(string str)
    {
        vector<int>ans;
        for(int i = 0 ;i < str.size();i++)
        {
            if(str[i] == '+' || str[i] == '-' || str[i] == '*')
            {
                vector<int>leftRes = solve(str.substr(0,i));
                vector<int>rightRes = solve(str.substr(i+1));

                for(int &x : leftRes)
                {
                    for(int &y : rightRes)
                    {
                        if(str[i] == '+')
                        {
                            ans.push_back(x+y);
                        }
                        else if(str[i]=='-')
                        {
                            ans.push_back(x-y);
                        }
                        else
                        {
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(ans.empty())
        {
            ans.push_back(stoi(str));
        }
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};

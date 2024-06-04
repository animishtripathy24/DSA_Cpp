class Solution
{
    private:
    void solve(int open,int close,string &ds,vector<string>&ans)
    {
        //base case
        if(open == 0 && close == 0)
        {
            ans.push_back(ds);
            return;
        }
        if(open > 0)
        {
            ds.push_back('(');
            solve(open-1,close,ds,ans);
            ds.pop_back();
        }
        if(close > 0 && open < close)
        {
            ds.push_back(')');
            solve(open,close-1,ds,ans);
            ds.pop_back();
        }
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string>ans;
        string ds;
        solve(n,n,ds,ans);
        return ans;
    }
};

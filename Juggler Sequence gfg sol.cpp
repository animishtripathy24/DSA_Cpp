class Solution {
  private:
    vector<int> solve(int n,vector<int>&ans)
    {
        if(n==1)
        {
            return ans;
        }
        ans.push_back(n);
        if(n&1)
        {
            n=n*sqrt(n);
            return solve(n,ans);
        }
        else
        {
            n=sqrt(n);
            return solve(n,ans);
        }
        
    }
  public:
    vector<int> jugglerSequence(int n) {
        if(n==1)
        {
            return {1};
        }
        vector<int>ans;
        vector<int>res=solve(n,ans);
        res.push_back(1);
        return res;
    }
};

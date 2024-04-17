// User function Template for C++
const int MOD=1e9+7;
class Solution {
  private:
    int solve(int n,int dp[])
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n]=(solve(n-1,dp)%MOD+solve(n-2,dp)%MOD)%MOD;
    }
  public:
    int nthFibonacci(int n){
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return solve(n,dp);
    }
};

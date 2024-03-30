class Solution {
private:
    int solveMem(int amount,vector<int>&coins,vector<int>&dp)
    {
        //base case
        if(amount == 0)
        {
            return 0;
        }
        if(dp[amount] != -1)
        {
            return dp[amount];
        }
        int mini=INT_MAX;
        for(auto coin:coins)
        {
            //jab tak mera amount greater than 0 rahega tab tak hi process karenge
            if(amount-coin>=0)
            {
                mini=min(mini+0LL,solveMem(amount-coin,coins,dp)+1LL); 
                //it may happen that the function INT_MAX somewhere hence
                //1 added for the current coin and comverted into long long because 1+INT_MAX is very big number
                //and min() function performs comparison of two similar number hence added 0LL with mini to convert it into a long long integer
            }
        }
        dp[amount]=mini;
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=solveMem(amount,coins,dp);
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};

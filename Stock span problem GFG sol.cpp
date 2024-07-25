class Solution
{
    private:
    void solve(int price[],vector<int>&ans,int n)
    {
        stack<pair<int,int>>s;
        int span = 1;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && price[i] >= s.top().first)
            {
                span +=s.top().second;
                s.pop();
            }
            ans.push_back(span);
            s.push({price[i],span});
            span = 1; 
        }
    }
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int>ans;
       solve(price,ans,n);
       return ans;
    }
};

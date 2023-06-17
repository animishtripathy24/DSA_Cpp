class Solution {
  public:
    string findMax(string N) {
        priority_queue<long long>maxi;
        for(long long i=0;i<N.size();i++)
        {
            maxi.push(N[i]);
        }
        
        string ans;
        while(maxi.size())
        {
            char temp=maxi.top();
            ans+=temp;
            maxi.pop();
        }
        
        return ans;
    }
};

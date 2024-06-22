class Solution {
  public:
    long long ExtractNumber(string sentence) {

        stringstream ss(sentence);
        vector<string>ans;
        string token = "";
        while(getline(ss,token,' '))
        {
            ans.push_back(token);
        }
        long long maxi=0LL;
        for(auto &sent:ans)
        {
            long long int res=0;
            for(auto&it:sent)
            {
                if(it == '9')
                {
                    res=0;
                    break;
                }
                else if(it >= '0' && it <= '8')
                {
                    res = res * 10 + ( it - '0' );
                }
            }
            maxi=max(maxi,res);
        }
        if(maxi == 0LL)
        {
            return -1LL;
        }
        return maxi;
        
    }
};

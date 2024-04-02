class Solution {
  public:
    string findSum(string X, string Y) {
        reverse(X.begin(), X.end());
        reverse(Y.begin(), Y.end());
        
        string ans = "";
        int carry = 0;
        int i = 0, j = 0;
        
        while (i < X.size() || j < Y.size() || carry) {
            int digitX = (i < X.size()) ? X[i] - '0' : 0;
            int digitY = (j < Y.size()) ? Y[j] - '0' : 0;
            
            int sum = digitX + digitY + carry;
            
            carry = sum / 10;
            sum %= 10;
            
            ans += (sum + '0');
            
            if (i < X.size()) i++;
            if (j < Y.size()) j++;
        }
        reverse(ans.begin(), ans.end());
        while(ans[0]=='0')
        {
            ans.erase(0,1);
        }
        if(ans=="") return "0";
        return ans;
        
    }
};

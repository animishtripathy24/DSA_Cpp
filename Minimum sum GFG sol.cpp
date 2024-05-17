class Solution{   
private:
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
public:
    string solve(int arr[], int n) {
        sort(arr,arr+n);
        string str1,str2;
        for(int i=0;i<n;i+=2)
        {
            str1.push_back((arr[i]+'0'));
        }
        for(int i=1;i<n;i+=2)
        {
            str2.push_back((arr[i]+'0'));
        }
        return findSum(str1,str2);
    }
};

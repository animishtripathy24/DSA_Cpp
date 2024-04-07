class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
        reverse(a,a+n);
        reverse(b,b+m);

        string ans = "";
        int carry = 0;
        int i = 0, j = 0;

        while (i < n || j < m || carry) {
            int sum=0;
            if(i<n)
            {
                sum+=a[i];
                i++;
            }
            if(j<m)
            {
                sum+=b[j];
                j++;
            }

            sum +=carry;

            carry = sum / 10;
            sum %= 10;

            ans += (sum + '0');
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

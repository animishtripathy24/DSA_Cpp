class Solution {
  private:
    vector<int> getBinary(long long num)
    {
        vector<int>v;
        for(int i=31;i>=0;i--)
        {
            v.push_back(((num >> i) & 1));
        }
        return v;
    }
    void getReverse(vector<int>&v)
    {
        int start=0;
        int end=v.size()-1;
        while(start<=end)
        {
            swap(v[start],v[end]);
            start++;
            end--;
        }
    }
    long long convertDecimal(vector<int>&v)
    {
        int n=v.size();
        long long y = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            y += v[i] * std::pow(2, n - i);
        }
        return y;
    }
  public:
    long long reversedBits(long long x) {
        vector<int>ans=getBinary(x);
        getReverse(ans);
        return convertDecimal(ans)/2LL;
    }
};

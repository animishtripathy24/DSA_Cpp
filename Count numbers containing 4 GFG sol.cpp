class Solution {
  private:
    bool isContain4(int n)
    {
        while(n > 0)
        {
            int rem=n%10;
            if(rem == 4)
            {
                return 1;
            }
            n/=10;
        }
        return 0;
    }
  public:
    int countNumberswith4(int n) {
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(isContain4(i))
            {
                count++;
            }
        }
        return count;
    }
};

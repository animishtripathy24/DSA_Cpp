class Solution {
  public:
    int countPrimes(int L, int R) {
        vector<int>prime(R+1,true);
        //at first we will assume that all are prime numbers
        //then we will take a count
        int count=0;
        //mark the 0 and 1 as non prime 
        prime[0]=prime[1]=false;
        //loop from 2 to n-1 and accordingly mark the numbers as prime
        for(int i=2;i<R+1;i++)
        {
            if(prime[i] == true)
            {
                if(i >= L && i <= R)
                {
                    count++;
                }
                for(int j=2*i;j<R+1;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        return count;
    }
};

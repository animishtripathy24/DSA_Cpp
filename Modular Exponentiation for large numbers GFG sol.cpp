class Solution
{
    private:
    long long int power(long long int x, long long int n, long long int M)
    {
        // base case
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x % M;
        }

        long long int ans = power(x, n / 2, M);
        ans = (ans * ans) % M;

        // if n is odd
        if (n & 1)
        {
            ans = (ans * x) % M;
        }
        return ans;
    }

    public:
    long long int PowMod(long long int x, long long int n, long long int M)
    {
        return power(x, n, M);
    }
};

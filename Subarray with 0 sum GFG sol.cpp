class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        int count=0;
        unordered_map<int,int>m;
        m[0]=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(m.find(sum-0)!=m.end())
            {
                count++;
                m[sum-0]++;
            }
            else
            {
                m[sum]++;
            }
        }
        if(count)
        {
            return 1;
        }
        return 0;
    }
};

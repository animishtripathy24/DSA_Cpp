class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<long long>prefix;
        vector<long long>suffix;

        long long maxi_left=0LL;
        long long maxi_right=0LL;
        
        //calculating prefix max
        for(int i=0;i<n;i++)
        {
            maxi_left=max(maxi_left,(arr[i]+0LL));
            prefix.push_back(maxi_left);
        }

        // for(auto &it:prefix)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;

        //calculating suffix max
        for(int i=n-1;i>=0;i--)
        {
            maxi_right=max(maxi_right,(arr[i]+0LL));
            suffix.push_back(maxi_right);
        }
        reverse(suffix.begin(),suffix.end());
        // for(auto &it:suffix)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;
        long long amount=0LL;
        for(int i=0;i<n;i++)
        {
            amount+=(min(prefix[i],suffix[i])-arr[i]);
        }
        return amount;
    }
};

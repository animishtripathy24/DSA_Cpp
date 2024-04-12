class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>prefix;
        vector<int>suffix;

        int maxi_left=0;
        int maxi_right=0;
        //calculating prefix max
        for(int i=0;i<height.size();i++)
        {
            maxi_left=max(maxi_left,height[i]);
            prefix.push_back(maxi_left);
        }

        // for(auto &it:prefix)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;

        //calculating suffix max
        for(int i=height.size()-1;i>=0;i--)
        {
            maxi_right=max(maxi_right,height[i]);
            suffix.push_back(maxi_right);
        }
        reverse(suffix.begin(),suffix.end());
        // for(auto &it:suffix)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;
        int amount=0;
        for(int i=0;i<height.size();i++)
        {
            amount+=(min(prefix[i],suffix[i])-height[i]);
        }
        return amount;

    }
};

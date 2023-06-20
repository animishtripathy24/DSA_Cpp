#include<vector>
class Solution {
public:
    void solve(int index,vector<vector<int>>&ans,vector<int>&v,vector<int>&nums)
    {
        //base case
        if(index>=nums.size())
        {
            ans.push_back(v);
            return;
        }
       //ek baar index wale position ko lena hai....
        v.push_back(nums[index]);
        solve(index+1,ans,v,nums);
      
        //ek baar index wale position ko  nhi lena hai....
        v.pop_back();
        solve(index+1,ans,v,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int index=0;
        solve(0,ans,v,nums);

        return ans;
        
    }
};

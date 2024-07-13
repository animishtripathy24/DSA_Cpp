class Solution {
public:
    static bool cmp(int a,int b)
    {
        string str1 = to_string(a);
        string str2 = to_string(b);
        return (str1+str2 > str2+str1);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string res="";
        for(auto &it:nums)
        {
            res+=to_string(it);
        }
        while(res[0]=='0')
        {
            res.erase(0,1);
        }
        if(res.empty())
        {
            return "0";
        }
        return res;
    }
};

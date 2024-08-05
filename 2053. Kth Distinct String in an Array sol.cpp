class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>m;
        for(auto &it : arr)
        {
            m[it]++;
        }   
        int count = 1;
        for(auto &value : arr)
        {
            if(m[value]==1)
            {
                k--;
            }
            if(k==0)
            {
                return value;
            }
        }
        return "";
    }
};

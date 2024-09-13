class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>prefix;
        int xori = 0;
        for(int i=0;i<arr.size();i++)
        {
            xori = xori ^ arr[i];
            prefix.push_back(xori);
        }
        vector<int>ans;
        for(auto &it : queries)
        {
            int first = it[0];
            int last = it[1];
            if(first == 0)
            {
                ans.push_back(prefix[last]);
            }
            else
            {
                ans.push_back(prefix[last] ^ prefix[first-1]);
            }
        }
        return ans;
    }
};

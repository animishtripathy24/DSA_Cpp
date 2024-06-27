class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>indegree;
        for(auto &it:edges)
        {
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        for(auto &it:indegree)
        {
            if(it.second>1)
            {
                return it.first;
            }
        }
        return -1;
    }
};

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        stringstream ss(s1);
        string token = "";
        while (getline(ss, token, ' ')) {
            m[token]++;
        }
        stringstream ss1(s2);
        string token1 = "";
        while (getline(ss1, token1, ' ')) {
            m[token1]++;
        }
        vector<string> ans;
        for (auto it : m) {
            if (it.second == 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};

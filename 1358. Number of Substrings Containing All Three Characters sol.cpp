class Solution {
public:
    int numberOfSubstrings(string s) {
    vector<int>lastSeen(3,-1);
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
        lastSeen[s[i] - 'a']=i;
        count = count + (1 + *min_element(begin(lastSeen),end(lastSeen)));
    }
    return count;
    }
};

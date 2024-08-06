class Solution {
public:
    bool static cmp(int &a ,int &b)
    {
        return a > b;
    }
    int minimumPushes(string word) {
        //at first we have to keep track of the frequency of each character
        vector<int>m(26,0);

        for(auto &it : word)
        {
            m[it-'a']++;
        }

        sort(begin(m),end(m),cmp);

        int res = 0;
        //traverse in the array
        for(int i=0;i<26;i++)
        {
            int freq = m[i];

            int press = (i/8)+1;

            res+=(press * freq);
        }
        return res;
    }
};

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int baskets=2;
        unordered_map<int,int>m;
        int i=0;
        int j=0;
        int maxi = 0;
        while(j<fruits.size())
        {
            m[fruits[j]]++;
            if(m.size() <= baskets)
            {
                maxi = max(maxi,j-i+1);
                j++;
            }
            else
            {
                // cout << fruits[i] << endl;
                while(m.size() > baskets && i < j)
                {
                    // cout << fruits[i] << endl;
                    m[fruits[i]]--;
                    if(m[fruits[i]]==0)
                    {
                        m.erase(fruits[i]);
                    }
                    i++;
                }
                maxi = max(maxi,j-i+1);
                j++;
            }
            // for(auto &it:m)
            // {
            //     cout << it.first << " " << it.second << endl;
            // }
            // cout << endl << endl;
        }
        return maxi;
    }
};

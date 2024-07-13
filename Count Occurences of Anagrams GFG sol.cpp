//User function template for C++
class Solution{
private:
    bool allZero(unordered_map<char,int>&m)
    {
        for(auto &it:m)
        {
            if(it.second != 0)
            {
                return 0;
            }
        }
        return 1;
    }
public:
	int search(string pat, string txt) {
	    unordered_map<char,int>m;
	    for(char ch : pat)
	    {
	        m[ch]++;
	    }
	    int i=0;
	    int j=0;
	    int k= pat.size();
	    int count = 0;
	    while(j<txt.size())
	    {
            m[txt[j]]--;
            if(j-i+1 < k)
            {
                j++;
            }
            else
            {
                if(allZero(m))
                {
                    count++;
                }
                m[txt[i]]++;
                i++;
                j++;
            }
	    }
	    return count;
	}

};

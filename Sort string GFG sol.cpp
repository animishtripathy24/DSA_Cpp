class Solution
{	private:
        bool isvowel(char ch) 
        { 
            return (ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') ||(ch == 'u');
        }
    public:
		string SortedString(string s)
		{
		    map<char,int>vowel;
		    map<char,int>consonent;
		    for(int i=0;i<s.size();i++)
		    {
		        if(isvowel(s[i]))
		        {
		            vowel[s[i]]++;
		        }
		        else
		        {
		            consonent[s[i]]++;
		        }
		    }
		    string ans;
		    while(vowel.size()>0 && consonent.size()>0)
		    {
                if(isvowel(s[0]))
                {
                    auto it=vowel.begin();
    		        ans.push_back(it->first);
    		        it->second--;
    		        if(it->second == 0) vowel.erase(it);
    		        auto itt=consonent.begin();
    		        ans.push_back(itt->first);
    		        itt->second--;
    		        if(itt->second == 0) consonent.erase(itt);
                }
                else
                {
                    auto itt=consonent.begin();
    		        ans.push_back(itt->first);
    		        itt->second--;
    		        if(itt->second == 0) consonent.erase(itt);
                    auto it=vowel.begin();
    		        ans.push_back(it->first);
    		        it->second--;
    		        if(it->second == 0) vowel.erase(it);
                }
		        
		    }
		    while(vowel.size()>0)
		    {
		        auto it=vowel.begin();
		        ans.push_back(it->first);
		        it->second--;
		        if(it->second == 0) vowel.erase(it);
		    }
		    while(consonent.size()>0)
		    {
		        auto itt=consonent.begin();
		        ans.push_back(itt->first);
		        itt->second--;
		        if(itt->second == 0) consonent.erase(itt);
		    }
		    return ans;
		}

};

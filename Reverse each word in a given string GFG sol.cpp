class Solution
{
  public:
    string reverseWords (string s)
    {
        s.push_back('.');
        string ans;
        int i=0;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='.')
            {
                string temp(s.begin()+i,s.begin()+j);
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans.push_back('.');
                i=j+1;
            }
        }
        //revert the changes of the input string
        s.pop_back();
        ans.pop_back();
        return ans;
    }
};

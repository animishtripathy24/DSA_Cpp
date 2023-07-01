class Solution {
public:
    string sortSentence(string s) {
        s.push_back(' ');
        map<int,string>m;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                string temp(s.begin()+j,s.begin()+i-1);
                m[(s[i-1]-'0')]=temp;
                j=i+1;
            }
        }
        string str;
        for(auto &value:m)
        {
            str+=value.second;
            str.push_back(' ');
        }
        str.pop_back();
        return str;
        
    }
};

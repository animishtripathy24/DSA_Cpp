class Solution {
  public:
    string compareFrac(string str) {
        stringstream ss(str);
        string token = "";
        vector<string> ans;
        while (getline(ss, token, ',')) 
        {
            ans.push_back(token);
        }
        
        int a, b, c, d;
        {
            string fraction1 = ans[0];
            stringstream ss1(fraction1);
            string temp;
                
            getline(ss1, temp, '/');
            a = stoi(temp);
            getline(ss1, temp, '/');
            b = stoi(temp);
        }
        
        {
            string fraction2 = ans[1];
            stringstream ss2(fraction2);
            string temp;
                
            getline(ss2, temp, '/');
            c = stoi(temp);
            getline(ss2, temp, '/');
            d = stoi(temp);
        }
        int res1 = (a * d);
        int res2 = (b * c);
        if (res1 == res2) 
        {
            return "equal";
        } 
        else
        {
            if(res1 > res2)
            {
                return ans[0];
            }
            else
            {
                ans[1].erase(0,1);
                return ans[1];
            }
        }
    }
};

class Solution {
  public:
    int isValid(string str) {
        stringstream ss(str);
        string token = "";
        int count = 0;
        while(getline(ss,token,'.'))
        {
            int n = stoi(token);
            if(n>=0 && n<=255)
            {
                count++;
            }
        }
        return count==4;
    }
};

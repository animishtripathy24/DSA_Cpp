class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
       sort(arr.begin(),arr.end());
       string str1= arr[0];
       string str2= arr[arr.size()-1];
       int i=0;
       int j=0;
       string ans = "";
       while(i<str1.size() && j<str2.size())
       {
           if(str1[i]==str2[j])
           {
               ans.push_back(str1[i]);
           }
           else
           {
               break;
           }
           i++;
           j++;
       }
       return ans.size() == 0 ? "-1" : ans;
    }
};

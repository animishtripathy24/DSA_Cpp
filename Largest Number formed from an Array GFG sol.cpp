class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	static bool cmp(string &str1,string &str2)
	{
	    return (str1+str2)>(str2+str1);
	}
	string printLargest(int n, vector<string> &arr) {
	    sort(arr.begin(),arr.end(),cmp);
	    string str="";
	    for(int i=0;i<arr.size();i++)
	    {
	        str+=arr[i];
	    }
	    return str;
	}
};

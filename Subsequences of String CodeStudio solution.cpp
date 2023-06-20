#include <bits/stdc++.h> 

void solve(int index,vector<string>&v,string s,string &str)
{
	//base case
	if(index >= str.size())
	{
		if(s.size() !=0)
			v.push_back(s);
		return;
	}

	//ek baaar index wale position ko lena hai..(Take)
	s.push_back(str[index]);
	solve(index+1,v,s,str);

	//ek baar index wale position ko chorna hai..(NOT TAKE)
	s.pop_back();
	solve(index+1,v,s,str);	
}
vector<string> subsequences(string str){
	
	int index=0;
	vector<string>v;
	string s;
	solve(index,v,s,str);

	return v;
	
}

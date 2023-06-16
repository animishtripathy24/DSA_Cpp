#include<bits/stdc++.h>
using namespace std;
//declaring unordered_map as time complexity is O(1).
unordered_map<char,int>m={{'[',-1} , {'{',-2} , {'(',-3} , {']',1} , {'}',2} , {')',3} };
string isBalanced(string &s)
{
	
	stack<char>st;
	for(char &value:s)
	{
		if(m[value]<0)
		{
			st.push(value);
		}
		else
		{
			if(st.empty())
			{
				return "NO";
			}
			char top=st.top();
			st.pop();
			if(m[top]+m[value]!=0)
			{
				return "NO";
			}
		}
	}
	if(st.empty())
	{
		return "YES";
	}
	else
	{
		return "NO";
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string str;
		cin >> str;
		cout << isBalanced(str) << endl;
	}
}

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int lcs(string s, string t) {

	// Base Case
	if (s.size()==0 || t.size()==0)
	{
		return 0;
	}

	// Recursive Calls
	if (s[0]==t[0])
	{
		return 1+lcs(s.substr(1),t.substr(1));
	}

	else
		{
			int a = lcs(s.substr(1),t);
			int b = lcs(s,t.substr(1));
			int c = lcs(s.substr(1),t.substr(1));
			return max(a,max(b,c));
		}
}

int main()
{
	string s,t;
	cin>>s;
	cin>>t;
	cout << lcs(s,t) << endl;
}
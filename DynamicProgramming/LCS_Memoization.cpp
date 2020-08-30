#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int lcs(string s, string t, int **output) {

	int m = s.size();
	int n = t.size();
	// Base Case
	if (s.size()==0 || t.size()==0)
	{
		return 0;
	}

	if (output[m][n]!=-1)
	{
		return output[m][n];
	}

	int ans;
	// Recursive Calls
	if (s[0]==t[0])
	{
		ans= 1+lcs(s.substr(1),t.substr(1),output);
	}

	else
		{
			int a = lcs(s.substr(1),t,output);
			int b = lcs(s,t.substr(1),output);
			int c = lcs(s.substr(1),t.substr(1),output);
			ans = max(a,max(b,c));
		}

	output[m][n] = ans;
	return ans; 
}

int lcs(string s, string t) {
	int m = s.size();
	int n = t.size();

	int **output = new int *[m+1];

	for (int i = 0; i <= m; i++)
	{
		output[i] = new int [n+1];
		for (int j = 0; j <= n; j++)
		{
			output[i][j] = -1;
		}
	}

	return lcs(s,t,output);
}
int main()
{
	string s,t;
	cin>>s;
	cin>>t;
	cout << lcs(s,t) << endl;
}
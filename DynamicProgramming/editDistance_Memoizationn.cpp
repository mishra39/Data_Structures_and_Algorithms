#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
using namespace std;

int editDistance(string s1, string s2, int **output)
{	
	int m = s1.size();
	int n = s2.size();

	// Base Case: String ends
	if (s1.size() == 0 || s2.size() == 0)
	{
		return max(s1.size(),s2.size());
	} 

	if(output[m][n]!=-1)
	{
		return output[m][n];
	}
	
	int ans;
	// Recursion Calls with each operation
	// Small Calc: Try three operations and choose one with minimum steps

	if (s1[0] == s2[0])
	{
		return editDistance(s1.substr(1),s2.substr(1),output);
	}

	else
	{
		// Insert
		int a = editDistance(s1.substr(1),s2,output)+1;

		// Delete
		int b = editDistance(s1,s2.substr(1), output)+1;

		// Replace
		int c = editDistance(s1.substr(1),s2.substr(1),output)+1;

		output[m][n] =  min(a,min(b,c));
		return output[m][n];
	}
}

int editDistance(string s1, string s2){ // function returns the number of steps for making the string similar
	int m = s1.size();
	int n = s2.size();

	int **output = new int*[m+1];

	for (int i = 0; i <=m ; i++)
	{
		output[i] = new int[n+1];

		for(int j=0;j<=n+1;j++)
		{
			output[i][j] = -1; 
		}
	}

	return editDistance(s1,s2,output);
}

int main()
{
	string s1,s2;
	cin >> s1;
	cin >> s2;

	cout << editDistance(s1,s2) << endl;
}
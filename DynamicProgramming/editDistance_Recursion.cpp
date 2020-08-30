#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
using namespace std;

int editDistance(string s1, string s2){ // function returns the number of steps for making the string similar

	// Base Case: String ends
	if (s1.size() == 0 || s2.size() == 0)
	{
		return max(s1.size(),s2.size());
	} 

	// Recursion Calls with each operation
	// Small Calc: Try three operations and choose one with minimum steps

	if (s1[0] == s2[0])
	{
		return editDistance(s1.substr(1),s2.substr(1));
	}

	else
	{
		// Insert
		int a = editDistance(s1.substr(1),s2)+1;

		// Delete
		int b = editDistance(s1,s2.substr(1))+1;

		// Replace
		int c = editDistance(s1.substr(1),s2.substr(1))+1;

		return min(a,min(b,c));

	}
}

int main()
{
	string s1,s2;
	cin >> s1;
	cin >> s2;

	cout << editDistance(s1,s2) << endl;
}
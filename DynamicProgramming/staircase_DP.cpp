#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long staircase(int n)
{
	long *minArr = new long[n+1];
	minArr[0] = 1;
	minArr[1] = 1;
	minArr[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		minArr[i] = minArr[i-1] + minArr[i-2] + minArr[i-3];
	}

	return minArr[n];		
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n) << endl;
}
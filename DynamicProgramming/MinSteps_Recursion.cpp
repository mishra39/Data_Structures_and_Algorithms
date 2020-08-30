#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countStepsToOne(int n)
{

	//Base Case
	if (n <= 1)
	{
		return 0;
	}

	// Small Calc and Recursion
	int ans1 = countStepsToOne(n-1);
	int ans2 = INT_MAX, ans3 = INT_MAX;

	if (n%2==0)
	{
		ans2 = countStepsToOne(n/2);
	}

	if (n%3==0)
	{
		ans3 = countStepsToOne(n/3);
	}

	return min(ans1, min(ans2,ans3))+1;
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n) << endl;
}
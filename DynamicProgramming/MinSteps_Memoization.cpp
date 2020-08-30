#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countStepsToOneHelper(int n, int* minArr)
{
	//Base Case
	if (n <= 1)
	{
		return 0;
	}

	// Check if output already exists
	if (minArr[n] != -1)
	{
		return minArr[n];
	}

	// Small Calc and Recursion
	int ans1 = countStepsToOneHelper(n-1,minArr	);
	int ans2 = INT_MAX, ans3 = INT_MAX;

	if (n%2==0)
	{
		ans2 = countStepsToOneHelper(n/2, minArr);
	}

	if (n%3==0)
	{
		ans3 = countStepsToOneHelper(n/3, minArr);
	}

	minArr[n] = min(ans1, min(ans2,ans3))+1;

	return minArr[n];
}


int countStepsToOne(int n)
{
	int *minArr = new int[n+1];

	for (int i = 0; i <= n; i++)
	{
		minArr[i] = -1;
	}

	return countStepsToOneHelper(n, minArr);

}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n) << endl;
}
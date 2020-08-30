#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countStepsToOne(int n)
{
	int *minArr = new int[n+1];
	minArr[0] = 0;
	minArr[1] = 0;
	

	for (int i = 2; i <= n; i++)
	{
		int ans1 = minArr[i-1];

		if (i % 2 == 0)
		{
			if (ans1 > minArr[i/2])
			{
				ans1 = minArr[i/2];
			}
		}

		if (i % 3 == 0)
		{
			if (ans1>minArr[i/3])
			{
				ans1 = minArr[i/3];
			}
		}

		minArr[i] = ans1+1;
	}

	return minArr[n];

}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n) << endl;
}
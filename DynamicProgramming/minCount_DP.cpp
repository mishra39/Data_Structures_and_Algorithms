#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
	int *res = new int[n+1];

	//initial values
	res[0] = 0;
	res[1] = 1;
	res[2] = 2;
	res[3] = 3;

	for (int i = 4; i <= n; i++)
	{
		res[i] = i;

		for (int x = 1; x <= ceil(sqrt(i)); x++)
		{
			int temp = x*x;
			if (temp > i)
			{
				break;
			}

			else
			{
				res[i] = min(res[i],1+res[i-temp]);
			}
		}
	}

	int ans = res[n];
	delete[] res;

	return ans;
}

int main() {
	int n;
	cin >> n;
	cout << minCount(n) << endl;
}
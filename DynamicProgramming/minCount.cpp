#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
	if (n<=0)
	{
		return 0;
	}

	int res = minCount(n-1);

	for (int i = 2; i <= n; i++)
	{
		if (n >= i*i)
		{
			res = min(res,minCount(n-(i*i)));
		}
	}

	return res+1;
	
}

int main() {
	int n;
	cin >> n;
	cout << minCount(n) << endl;
}
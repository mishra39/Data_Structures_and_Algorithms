#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int binaryTreesOfHeightH(int h) {

	int *ans = new int[h+1];
	int mod = (int) (pow(10,9))+7;
	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 3;

	for (int i = 3; i <= h; ++i)
	{	
		int x = (int) (((long) (ans[i-1])*ans[i-1])%mod);
		int y = (int) (((2*(long)ans[i-1]*ans[i-2]))%mod);
		ans[i] = (x+y)%mod;
	}

	return ans[h];
}

int main() {
	int n;
	cin >> n;
	cout << binaryTreesOfHeightH(n) << endl;
}
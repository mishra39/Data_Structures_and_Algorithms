#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int balancedBTs(int h) {

	// Base Case
	if (h<=1)
	{
		return 1;
	}

	int mod = (int) (pow(10,9))+7;
	// Recursion
	int x = balancedBTs(h-1);
	int y = balancedBTs(h-2);

	// Small Calc
	int temp1 = (int) (((long) (x)*x) % mod);
	int temp2 = (int) ((2*(long)x*y) % mod);

	int ans = (temp1 + temp2) % mod;
	return ans;

}

int main() {
	int n;
	cin >> n;
	cout << balancedBTs(n) << endl;
}
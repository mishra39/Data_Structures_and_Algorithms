#include <iostream>
using namespace std;
#include <cmath>

double geometricSum(int k){
	if (k==0){
		return 1;
	}

	double smallAns = geometricSum(k-1);

	return smallAns + (1/pow(2,k));
}

int main(int argc, char const *argv[])
{
	int k;
	cin >> k;
	cout << geometricSum(k) << endl;
	return 0;
}
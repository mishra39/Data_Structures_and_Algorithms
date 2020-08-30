#include <iostream>
using namespace std;

int sumofDigits(int n){
	if(n < 10){
		return n;
	}

	int smallAns = sumofDigits(n / 10);
	return smallAns + (n % 10);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << sumofDigits(n) << endl;
	return 0;
}
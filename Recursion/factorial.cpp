#include <iostream>
using namespace std;

int factorial(int n){

	if (n == 0) { //condition to stop recursion

		return 1;
	}

	int smallOutput = factorial(n-1);
	return n*smallOutput;
}

int main(int argc, char const *argv[])
{	
	int num,fact;
	cout << "Enter Number: ";
	cin >> num;
	fact = factorial(num);
	cout << "Factorial of " << num << " is " << fact << endl;
	return 0;
}
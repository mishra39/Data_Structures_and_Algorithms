#include <iostream>
using namespace std;

int staircase(int n) {
	//Base case
	cout << n;
	if (n==0 || n==1) {
		return 1;
	}

	else if (n==2) {
	return 2;	
	}
	//Recursion calls
	else {
			return staircase(n-1)+staircase(n-2)+staircase(n-3);

	}
}



int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}